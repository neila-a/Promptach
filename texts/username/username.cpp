#include <QDir>
#include <texts.h>

extern "C" coloredText entry() {
    return {QDir::home().dirName().trimmed(), USERNAME};
}
