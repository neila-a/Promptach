#ifndef CONSOLESIDE_H
#define CONSOLESIDE_H

#include <QList>
#include <QPair>
#include "../util/settings.h"

typedef std::pair<QString, TextType> coloredText;

class ConsoleSide : public QList<QPair<QString, TextType>> {
public:
    ConsoleSide(std::initializer_list<coloredText> init);
    const QString toString() const;
    const unsigned int totalLength() const;
};

#endif // CONSOLESIDE_H
