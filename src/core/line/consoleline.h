#ifndef CONSOLELINE_H
#define CONSOLELINE_H

#include <QList>
#include <QTextStream>
#include "./consoleside.h"

class ConsoleLine : public QList<ConsoleSide> {
public:
    ConsoleLine();
    void write(QTextStream* stream) const;

private:
    unsigned short space() const;
    unsigned short consoleWidth() const;
};

#endif // CONSOLELINE_H
