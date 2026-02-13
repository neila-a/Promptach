#include "settingswindow.h"

PromptachSettings::PromptachSettings(
    QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    initTextsView();
    connect(&settings, &Settings::synced, this, &PromptachSettings::updatePreviewer);
}

PromptachSettings::~PromptachSettings() {}

const int PromptachSettings::locatePreviewer() const {
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

void PromptachSettings::updatePreviewer() {
    const int index = locatePreviewer();

    ui.verticalLayout->removeWidget(ui.previewer);
    ui.previewer->deleteLater();
    ui.previewer = new Previewer(this);
    ui.verticalLayout->insertWidget(index, ui.previewer);

    initTextsView();
}
