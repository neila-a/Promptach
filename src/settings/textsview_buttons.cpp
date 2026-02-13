#include "settingswindow.h"

void PromptachSettings::on_addLine_clicked() {
    return settings.modifyTextsList(
        [](TextsList *list) -> void { list->append(QList{{QStringList{}}}); });
}

void PromptachSettings::on_removeLine_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void { list->remove(pos.at(0)); });
}

void PromptachSettings::on_addSide_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));

        thisLine.append(QStringList{});

        list->replace(pos.at(0), thisLine);
    });
}

void PromptachSettings::on_removeSide_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));

        thisLine.remove(pos.at(1));

        list->replace(pos.at(0), thisLine);
    });
}

void PromptachSettings::on_addText_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));
        QStringList thisSide = thisLine.at(pos.at(1));

        thisSide.append(QString());

        thisLine.replace(pos.at(1), thisSide);
        list->replace(pos.at(0), thisLine);
    });
}

void PromptachSettings::on_removeText_clicked() {
    return settings.modifyTextsList([this](TextsList *list) -> void {
        QList<QStringList> thisLine = list->at(pos.at(0));
        QStringList thisSide = thisLine.at(pos.at(1));

        thisSide.remove(pos.at(2));

        thisLine.replace(pos.at(1), thisSide);
        list->replace(pos.at(0), thisLine);
    });
}
