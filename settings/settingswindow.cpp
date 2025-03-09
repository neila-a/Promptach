#include "settingswindow.h"

SettingsWindow::SettingsWindow(
    QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    ui.pathAliasesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    initing = true;

    initTextsView();
    initPathAliasTable();

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

    initTextsView();
}

void SettingsWindow::on_timeFormatEdit_editingFinished() {
    const QString text = ui.timeFormatEdit->text();
    KConfigGroup generalGroup(&settings, "General");
    generalGroup.writeEntry("timeFormat", text);
    generalGroup.config()->sync();
}
