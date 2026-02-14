#include "settingswindow.h"
#include <write.h>

SettingsWindow::SettingsWindow(
    QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    connect(&settings, &Settings::synced, this, &SettingsWindow::updatePreviewer);
    updatePreviewer();
}

SettingsWindow::~SettingsWindow() {}

 void SettingsWindow::updatePreviewer() {
    QString preview;
    QTextStream stream(&preview);
    write(&stream);
    ui.previewer->setText(preview);
    initTextsView();
 }