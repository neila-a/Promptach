#include <QDir>
#include "./texts.h"
#include "./utils.h"

extern "C" coloredText entry() {
    QString output = run("git", {"rev-parse", "--show-prefix"}).replace("\n", ""), childPath = "";
    if (output.length() != 0) {
        output.chop(1);
        const QStringList all = qEnvironmentVariable("PWD", QDir::current().absolutePath())
                                    .trimmed()
                                    .split(QDir::separator());
        const QStringList splited = output.split(QDir::separator());
        const qsizetype outputLength = output.split(QDir::separator()).length();
        childPath = all.sliced(all.length() - outputLength).join(QDir::separator());
        return {replaceSymbolLink(all.sliced(0, all.length() - outputLength).join(QDir::separator()),
                                  childPath),
                GITCHILDPATH};
    }
    return {"", GITCHILDPATH};
}
