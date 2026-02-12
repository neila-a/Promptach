#include <settings.h>

const QString Settings::replacePath(QString path) const {
    QString replaced = path;

    const KConfigGroup pathAliases(this, "pathAliases");
    const QStringList paths = pathAliases.keyList();
    for (const QString& path : paths)
        replaced = replaced.replace(path, pathAliases.readEntry(path, QString()));

    return replaced;
}
