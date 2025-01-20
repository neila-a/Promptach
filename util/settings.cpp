#include "settings.h"
#include <QDir>
#include <QProcessEnvironment>

const QString configBase = QProcessEnvironment::systemEnvironment().value("XDG_CONFIG_HOME");
const QString configFile = QDir::toNativeSeparators(configBase + "/Promptach.ini");

Settings::Settings(
    QSettings *parent)
    : QSettings(configFile, QSettings::IniFormat) {}

const unsigned char Settings::operator[](
    TextType type) {
    beginGroup("colors");
    const unsigned char color = value(QString::number(type), type).value<unsigned char>();
    endGroup();
    return color;
}
