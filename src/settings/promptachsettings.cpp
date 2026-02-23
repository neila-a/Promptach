#include "promptachsettings.h"

#include <KPluginFactory>

K_PLUGIN_CLASS_WITH_JSON(PromptachSettings, "promptachsettings.json")

PromptachSettings::PromptachSettings(QObject *parent, const KPluginMetaData &data)
    : KQuickConfigModule(parent, data)
{
    setButtons(Apply | Default);
}

#include "promptachsettings.moc"