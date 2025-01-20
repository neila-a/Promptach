#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

enum TextType { PATH = 39, GITBRANCH = 220, GITCHILDPATH = 202, USERNAME = 46, TIME = 201 };

class Settings : public QSettings {
public:
    explicit Settings(QSettings *parent = nullptr);

    const QString replacePath(QString path);
    // color
    const unsigned char operator[](TextType);
};

#endif // SETTINGS_H
