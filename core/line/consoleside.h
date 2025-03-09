#ifndef CONSOLESIDE_H
#define CONSOLESIDE_H

#include <QList>
#include <QPair>
#include <settings.h>

typedef std::pair<QString, TextType> coloredText;
typedef coloredText (*textFunction)();
typedef void (*configFunction)(QWidget *parent, std::function<void()> synced);

class ConsoleSide : public QList<QPair<QString, TextType>> {
public:
    ConsoleSide();
    const QString toString() const;
    const qsizetype totalLength() const;
};

#endif // CONSOLESIDE_H
