#pragma once

#include <KQuickConfigModule>

class PromptachSettings : public KQuickConfigModule
{
    Q_OBJECT
    public:
        PromptachSettings(QObject *parent, const KPluginMetaData &data);
};