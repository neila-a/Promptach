#include <QDir>
#include "./texts.h"
#include "./utils.h"

QString gitParentPath() {
    return isInGit() ? run("git", {"rev-parse", "--show-toplevel"}).replace("\n", "")
                     : QDir::currentPath().trimmed();
}
