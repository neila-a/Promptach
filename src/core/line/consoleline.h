#ifndef CONSOLELINE_H
#define CONSOLELINE_H

#include <QList>
#include <QTextStream>
#include "./consoleside.h"

class ConsoleLine : public QList<ConsoleSide> {
public:
    ConsoleLine();
    const void write(QTextStream* stream) const;

private:
    const unsigned short space() const;
    const unsigned short consoleWidth() const;
};

#endif // CONSOLELINE_H
