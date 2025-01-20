#include "consoleline.h"

ConsoleLine::ConsoleLine(
    std::initializer_list<ConsoleSide> init) {
    for (ConsoleSide side : init) {
        append(side);
    }
}

const unsigned short ConsoleLine::space() const {
    unsigned short _space = consoleWidth();
    for (unsigned int i = 0; i < size(); i++) {
        _space -= at(i).totalLength();
    }
    return _space;
}

#ifdef Q_OS_UNIX
#include <sys/ioctl.h>
#endif
const unsigned short ConsoleLine::consoleWidth() const {
#ifdef Q_OS_UNIX
    struct winsize size;
    ioctl(0, TIOCGWINSZ, &size);
    return size.ws_col;
#else
    return 100;
#endif
}

const int ConsoleLine::write() const {
    QTextStream stream(stdout);
    for (unsigned int i = 0; i < size(); i++) {
        stream << at(i).toString();
        if (i < size() - 1) {
            stream << QString(" ").repeated(space());
        }
    }
    stream.flush();
    return 0;
}
