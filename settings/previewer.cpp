#include "previewer.h"
#include <KParts/ReadOnlyPart>
#include <KPluginFactory>
#include <KService>
#include <kde_terminal_interface.h>

Previewer::Previewer(
    QWidget *parent)
    : QWidget{parent} {
    try {
        const KPluginMetaData metaData
            = KPluginMetaData::findPluginById("/usr/lib/x86_64-linux-gnu/qt6/plugins/kf6/parts",
                                              "konsolepart");
        const KPluginFactory::Result<KPluginFactory> factory = KPluginFactory::loadFactory(metaData);
        KPluginFactory *plugin = factory.plugin;
        const QList empty = {QVariant()};
        KParts::ReadOnlyPart *part = plugin->create<KParts::ReadOnlyPart>(this, empty);
        TerminalInterface *interface = qobject_cast<TerminalInterface *>(part);
        interface->startProgram("Promptach", {});

        verticalLayout->addWidget(part->widget());
    } catch (...) {
    }
    setMaximumHeight(35);
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(verticalLayout);
}
