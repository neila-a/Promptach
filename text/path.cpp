#include "../util/settings.h"
#include "./texts.h"

coloredText path() {
    QString string = gitParentPath();
    Settings settings;
    return {settings.replacePath(string), PATH};
}

const QString Settings::replacePath(
    QString path) {
    QString replaced = path;

    beginGroup("pathAliases");

    const QStringList replacings = allKeys();
    for (unsigned int i = 0; i < replacings.size(); i++) {
        replaced = replaced.replace(replacings[i], value(replacings[i]).toString());
    }

    endGroup();

    return replaced;
}
