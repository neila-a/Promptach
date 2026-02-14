#include <QColumnView>
#include <textloader.h>
#include <QStandardItem>
#include <QDir>
#include "settingswindow.h"
#include <line/consoleside.h>
#include <textinterface.h>

typedef QList<QWidget*> QWidgetList;

void SettingsWindow::initTextsView() {
    const TextsList textsList = settings.getTextsList();
    QStandardItemModel* model = new QStandardItemModel;
    for (qsizetype lineIndex = 0; lineIndex < textsList.size(); lineIndex++) {
        QList<QStringList> thisLine = textsList.at(lineIndex);
        QStandardItem* thisLineItem = new QStandardItem(tr("第%1行").arg(lineIndex + 1));
        for (qsizetype sideIndex = 0; sideIndex < thisLine.size(); sideIndex++) {
            QStringList thisSide = thisLine.at(sideIndex);
            QStandardItem* thisSideItem = new QStandardItem(tr("第%1边").arg(sideIndex + 1));
            for (qsizetype textIndex = 0; textIndex < thisSide.size(); textIndex++) {
                QString thisText = thisSide.at(textIndex);
                QStandardItem* thisTextItem = new QStandardItem(thisText);
                thisSideItem->appendRow(thisTextItem);
            }
            thisLineItem->appendRow(thisSideItem);
        }
        model->appendRow(thisLineItem);
    }
    ui.textsView->setModel(model);
    ui.textsView->expandAll();
}

void SettingsWindow::on_textsView_clicked(
    const QModelIndex& index) {
    /*
     * 0: line
     * 1: side
     * 2: text
     */
    int level = -1;
    QList<int> _pos;

    QModelIndex parent = index;
    while (parent.isValid()) {
        _pos.prepend(parent.row());
        parent = parent.parent();
        level++;
    }
    pos = _pos;

    /*
     * It can't be place in constructor because pointer of widgets will have change.
     */
    const QList<QWidgetList> all = { {ui.removeLine, ui.addSide},
                                    {ui.removeSide, ui.addText, ui.removeText},
                                    {ui.removeText, ui.sourceEdit, ui.formatEdit, ui.configWidget} };
    for (qsizetype i = 0; i < all.size(); i++)
        if (i <= level) {
            for (QWidget* enable : all.at(i))
                enable->setEnabled(true);
            if (i < 2)
                for (QWidget* disable : all.at(i + 1))
                    disable->setEnabled(false);
        }

    if (level == 2) {
        ui.sourceEdit->setText(settings.getTextsList().at(pos.at(0)).at(pos.at(1)).at(pos.at(2)));
        initFormatEdit();
    } else {
        recreateConfigWidget();
    }
}

void SettingsWindow::recreateConfigWidget() {
    delete ui.configWidget;
    ui.configWidget = new QWidget(ui.centralwidget);
    ui.configWidget->setObjectName("configWidget");

    ui.verticalLayout_5->insertWidget(2, ui.configWidget);
}

void SettingsWindow::initFormatEdit() {
    TextLoader textLoader(ui.sourceEdit->text());
    QObject* gotTextPlugin = textLoader.instance();
    recreateConfigWidget();
    if (gotTextPlugin) {
        TextInterface* textPlugin = qobject_cast<TextInterface*>(gotTextPlugin);
        ui.formatEdit->setText(settings[textPlugin->getText().second]);
        textPlugin->drawConfigInterface(ui.configWidget, [this]() -> void { updatePreviewer(); });
        ui.configWidget->show();
    }
    ui.formatEdit->setEnabled(textLoader.isLoaded());
}

void SettingsWindow::on_sourceEdit_editingFinished() {
    settings.modifyTextsList([this](TextsList* list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));
        QStringList thisSide = thisLine.at(pos.at(1));

        thisSide.replace(pos.at(2), ui.sourceEdit->text());

        thisLine.replace(pos.at(1), thisSide);
        list->replace(pos.at(0), thisLine);
        });
    return initFormatEdit();
}

void SettingsWindow::on_formatEdit_editingFinished() {
    KConfigGroup formats(&settings, "format");
    /*
     * It must be loadable because if it isn't loadable it will not be edited.
     */

    QPluginLoader textLoader("promptach/texts" + ui.sourceEdit->text());
    QObject* gotTextPlugin = textLoader.instance();
    if (gotTextPlugin) {
        TextInterface* textPlugin = qobject_cast<TextInterface*>(gotTextPlugin);
        formats.writeEntry(QString::number(textPlugin->getText().second), ui.formatEdit->text());
        formats.config()->sync();
    }
}
