#include "settingswindow.h"
SettingsWindow::SettingsWindow(
    QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    ui.pathAliasesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    initing = true;

    const KConfigGroup pathAliases(&settings, "pathAliases");
    const QStringList paths = pathAliases.keyList();
    for (const QString &path : paths) {
        int rowCount = on_addAlias_clicked();
        ui.pathAliasesTable->setItem(rowCount, 0, new QTableWidgetItem(path));
        ui.pathAliasesTable->setItem(rowCount,
                                     1,
                                     new QTableWidgetItem(pathAliases.readEntry(path, QString())));
    }

    initing = false;

    KConfigGroup generalGroup(&settings, "General");
    ui.timeFormatEdit->setText(generalGroup.readEntry("timeFormat", "HH:mm"));

    connect(&settings, &Settings::synced, this, &SettingsWindow::updatePreviewer);
}

SettingsWindow::~SettingsWindow() {}

const int SettingsWindow::locatePreviewer() const {
    int index;
    for (int i = 0; i < ui.verticalLayout->count(); i++) {
        QLayoutItem *item = ui.verticalLayout->itemAt(i);
        QWidget *widget = item->widget();
        if (widget == ui.previewer) {
            index = i;
            break;
        }
    }
    return index;
}

void SettingsWindow::updatePreviewer() {
    const int index = locatePreviewer();

    ui.verticalLayout->removeWidget(ui.previewer);
    ui.previewer->deleteLater();
    ui.previewer = new Previewer(this);
    ui.verticalLayout->insertWidget(index, ui.previewer);
}

void SettingsWindow::on_timeFormatEdit_textEdited(
    const QString &text) {
    KConfigGroup generalGroup(&settings, "General");
    generalGroup.writeEntry("timeFormat", text);
    generalGroup.config()->sync();
}

