#include "./texts.h"
#include "pathaliastable.h"
#include <settings.h>

extern "C" coloredText entry() {
    QString string = gitParentPath();
    Settings settings;
    return {settings.replacePath(string), PATH};
}

extern "C" void config(
    QWidget *parent, std::function<void()> synced) {
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);

    PathAliasTable *table = new PathAliasTable(synced);
    layout->addWidget(table);

    parent->setLayout(layout);
}

const QString Settings::replacePath(
    QString path) const {
    QString replaced = path;

    const KConfigGroup pathAliases(this, "pathAliases");
    const QStringList paths = pathAliases.keyList();
    for (const QString &path : paths)
        replaced = replaced.replace(path, pathAliases.readEntry(path, QString()));

    return replaced;
}
