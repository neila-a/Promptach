#ifndef BUILTINTEXTSLIST_H
#define BUILTINTEXTSLIST_H

#include <QStringList>

typedef QList<QList<QStringList>> TextsList;

class BuiltInTextsList : public QStringList {
public:
    BuiltInTextsList(
        std::initializer_list<QString> init) {
        for (const QString &text : init) {
            append(PromptachBuiltInTextsPrefix + text);
        }
    }
};

#endif // BUILTINTEXTSLIST_H
