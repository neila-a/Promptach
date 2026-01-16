#ifndef USERNAME_H
#define USERNAME_H

#include <texts.h>
#include <textinterface.h>
#include <QDir>

class Username : public QObject, public TextInterface {
    Q_OBJECT;
    Q_PLUGIN_METADATA(IID TextInterface_iid);
    Q_INTERFACES(TextInterface);

public:
    coloredText getText() {
        return { QDir::home().dirName().trimmed(), USERNAME };
    };
};

#endif