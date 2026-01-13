#ifndef SETTINGS_H
#define SETTINGS_H

#include "./PromptachSettingsBackend_global.h"
#include "./builtintextslist.h"
#include <KConfig>
#include <KConfigGroup>

enum TextType { PATH = 39, GITBRANCH = 220, GITCHILDPATH = 202, USERNAME = 46, TIME = 201 };

class PROMPTACHSETTINGSBACKEND_EXPORT Settings : public QObject, public KConfig {
    Q_OBJECT
public:
    explicit Settings(KConfig *parent = nullptr);

    const QString replacePath(QString path) const;
    bool sync() override;
    // format
    const QString operator[](TextType) const;

    void modifyTextsList(std::function<void(TextsList *list)> modifier);
    const TextsList getTextsList() const;

    static const QString getTextsDir();
signals:
    void synced();
};

#endif // SETTINGS_H
