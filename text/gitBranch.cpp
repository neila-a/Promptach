#include "./texts.h"

coloredText gitBranch() {
    const bool isGit = isInGit();
    QString branch = "";
    if (isGit) {
        branch = run("bash", {"-c", "source /usr/lib/git-core/git-sh-prompt && __git_ps1 %s"});
    }
    return {branch, GITBRANCH};
}
