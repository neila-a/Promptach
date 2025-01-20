#include "consoleside.h"
ConsoleSide::ConsoleSide(
    std::initializer_list<coloredText> init) {
    for (coloredText text : init) {
        append(text);
    }
}

const unsigned int ConsoleSide::totalLength() const {
    unsigned int length = 0;
    for (unsigned int i = 0; i < size(); i++) {
        length += at(i).first.length() + 1;
    }
    return length - 1;
}

const QString ConsoleSide::toString() const {
    Settings settings;
    QString string = "";
    for (unsigned int i = 0; i < size(); i++) {
        QString text = at(i).first;

        string += "\e[38;5;";
        string += QString::number(settings[at(i).second]);
        string += "m";
        string += text;

        if (i < size() - 1) {
            string += " ";
        }
    }
    string += "\e[0m";
    return string;
}
