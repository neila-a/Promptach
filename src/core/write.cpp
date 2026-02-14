#include <QDir>
#include "textloader.h"
#include <QTime>
#include "./line/consoleline.h"
#include "./line/consoleside.h"
#include <errno.h>
#include <settings.h>
#include "./textinterface.h"
#include "write.h"

int write(QTextStream* stream) {
    int errorNumber = 0;

    const Settings settings;
    const TextsList textsList = settings.getTextsList();
    for (const QList<QStringList>& line : textsList) {
        ConsoleLine consoleLine;
        for (const QStringList& side : line) {
            ConsoleSide consoleSide;
            for (QString text : side) {
                TextLoader textLoader(text);
                QObject* gotTextPlugin = textLoader.instance();
                if (gotTextPlugin) {
                    TextInterface* textPlugin = qobject_cast<TextInterface*>(gotTextPlugin);
                    consoleSide.append(textPlugin->getText());
                } else {
                    qCritical().noquote() << textLoader.errorString();
                    errorNumber = ELIBACC;
                }
            }
            consoleLine.append(consoleSide);
        }
        consoleLine.write(stream);
    }

    return errorNumber;
}
