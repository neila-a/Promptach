#include "./texts.h"

coloredText gitBranch() {
    const bool isGit = isInGit();
    QString branch = "";
    if (isGit) {
        branch = run("git", {"branch", "--show-current"}).trimmed();
    }
    return {branch, GITBRANCH};
}
