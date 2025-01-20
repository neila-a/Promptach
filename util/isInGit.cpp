#include "./utils.h"

bool isInGit() {
    const QString output = run("git", {"rev-parse", "--is-inside-work-tree"});
    return output == "true\n";
}
