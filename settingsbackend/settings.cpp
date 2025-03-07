#include "settings.h"
#include <QDir>
#include <QProcessEnvironment>

Settings::Settings(
    KConfig *parent)
    : KConfig("Promptach")
    , QObject() {}

const QString Settings::operator[](
    TextType type) {
    QString typeNumber = QString::number(type);
    const KConfigGroup formats(this, "format");
    const QString color = formats.readEntry(typeNumber, "38;5;" + typeNumber);
    return color;
}

bool Settings::sync() {
    bool done = KConfig::sync();
    emit synced();
    return done;
}
