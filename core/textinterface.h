#ifndef TEXTINTERFACE_H
#define TEXTINTERFACE_H

#include "line/consoleside.h"
#include <QtPlugin>

class TextInterface {
public:
    virtual ~TextInterface() {}
    virtual coloredText getText() = 0; // Required
    virtual void drawConfigInterface(QWidget* parent, std::function<void()> synced) {

    } // Optional
};

QT_BEGIN_NAMESPACE
#define TextInterface_iid "vip.neila.promptach.TextInterface"
Q_DECLARE_INTERFACE(TextInterface, TextInterface_iid)
QT_END_NAMESPACE

#endif