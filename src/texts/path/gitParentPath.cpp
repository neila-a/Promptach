#include <QDir>
#include <texts.h>
#include <utils.h>

QString gitParentPath() {
    const QString all = qEnvironmentVariable("PWD", QDir::current().absolutePath()).trimmed();
    return isInGit() ? all.split(QDir::separator())
                           .sliced(0,
                                   run("git", {"rev-parse", "--show-toplevel"})
                                       .replace("\n", "")
                                       .split(QDir::separator())
                                       .length())
                           .join(QDir::separator())
                     : all;
}
