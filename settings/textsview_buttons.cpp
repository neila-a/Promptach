#include "settingswindow.h"

void SettingsWindow::on_addLine_clicked() {
    return settings.modifyTextsList(
        [](TextsList *list) -> void { list->append(QList{{QStringList{}}}); });
}

void SettingsWindow::on_removeLine_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void { list->remove(pos.at(0)); });
}

void SettingsWindow::on_addSide_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));

        thisLine.append(QStringList{});

        list->replace(pos.at(0), thisLine);
    });
}

void SettingsWindow::on_removeSide_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));

        thisLine.remove(pos.at(1));

        list->replace(pos.at(0), thisLine);
    });
}

void SettingsWindow::on_addText_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));
        QStringList thisSide = thisLine.at(pos.at(1));

        thisSide.append(QString());

        thisLine.replace(pos.at(1), thisSide);
        list->replace(pos.at(0), thisLine);
    });
}

void SettingsWindow::on_removeText_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));
        QStringList thisSide = thisLine.at(pos.at(1));

        thisSide.remove(pos.at(2));

        thisLine.replace(pos.at(1), thisSide);
        list->replace(pos.at(0), thisLine);
    });
}
