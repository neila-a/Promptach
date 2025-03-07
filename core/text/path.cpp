#include "./texts.h"
#include <settings.h>

coloredText path() {
    QString string = gitParentPath();
    Settings settings;
    return {settings.replacePath(string), PATH};
}

const QString Settings::replacePath(
    QString path) {
    QString replaced = path;

    KConfigGroup pathAliases(this, "pathAliases");
    QStringList paths = pathAliases.keyList();
    for (const QString &path : paths) {
        replaced = replaced.replace(path, pathAliases.readEntry(path, QString()));
    }

    return replaced;
}
