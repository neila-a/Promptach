#include <QDir>
#include "./texts.h"
#include "./utils.h"

QString gitParentPath() {
    const bool isGit = isInGit();
    if (isGit) {
        return run("git", {"rev-parse", "--show-toplevel"}).replace("\n", "");
    } else {
        return QDir::currentPath().trimmed();
    }
}
