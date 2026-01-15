#include <texts.h>
#include <utils.h>

extern "C" coloredText entry() {
    const bool isGit = isInGit();
    QString branch = isGit ? run("git", {"branch", "--show-current"}).trimmed() : "";
    return {branch, GITBRANCH};
}
