#ifndef PATH_H
#define PATH_H

#include "pathaliastable.h"
#include <texts.h>
#include <textinterface.h>
#include <utils.h>
#include <settings.h>

class Path : public QObject, public TextInterface {
    Q_OBJECT;
    Q_PLUGIN_METADATA(IID TextInterface_iid);
    Q_INTERFACES(TextInterface);

public:
    coloredText getText() {
        QString string = replaceSymbolLink("", gitParentPath());
        Settings settings;
        return { settings.replacePath(string), PATH };
    };
    void drawConfigInterface(QWidget* parent, std::function<void()> synced) {
        QHBoxLayout* layout = new QHBoxLayout;
        layout->setContentsMargins(0, 0, 0, 0);

        PathAliasTable* table = new PathAliasTable(synced);
        layout->addWidget(table);

        parent->setLayout(layout);
    };
};

#endif