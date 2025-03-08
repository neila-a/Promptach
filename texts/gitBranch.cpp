#include "./texts.h"
#include "./utils.h"

extern "C" coloredText entry() {
    const bool isGit = isInGit();
    QString branch = "";
    if (isGit) {
        branch = run("git", {"branch", "--show-current"}).trimmed();
    }
    return {branch, GITBRANCH};
}
