#include "consoleline.h"

ConsoleLine::ConsoleLine() {}

const unsigned short ConsoleLine::space() const {
    unsigned short _space = consoleWidth();
    for (qsizetype i = 0; i < size(); i++)
        _space -= at(i).totalLength();
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

const void ConsoleLine::write() const {
    QTextStream stream(stdout);
    for (qsizetype i = 0; i < size(); i++) {
        stream << at(i).toString();
        if (i < size() - 1)
            stream << QStringLiteral(" ").repeated(space() / (length() - 1));
    }
    stream.flush();
    return;
}
