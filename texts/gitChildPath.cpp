#include "./texts.h"
#include "./utils.h"

extern "C" coloredText entry() {
    QString output = run("git", {"rev-parse", "--show-prefix"}).replace("\n", ""), childPath = "";
    if (output.length() != 0) {
        output.chop(1);
        childPath = output;
    }
    return {childPath, GITCHILDPATH};
}
