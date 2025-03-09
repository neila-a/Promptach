#include <QCoreApplication>
#include <QDir>
#include <QLibrary>
#include <QTime>
#include "./line/consoleline.h"
#include "./line/consoleside.h"
#include <errno.h>
#include <promptachcommandlineparser.h>
#include <settings.h>

int main(
    int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);
    int errorNumber = 0;

    const Settings settings;
    const TextsList textsList = settings.getTextsList();
    for (const QList<QStringList> &line : textsList) {
        ConsoleLine consoleLine;
        for (const QStringList &side : line) {
            ConsoleSide consoleSide;
            for (QString text : side) {
                QLibrary library(TEXTSDIR + text);
                textFunction _return = (textFunction) library.resolve("entry");
                if (_return) {
                    consoleSide.append(_return());
                } else {
                    qCritical().noquote() << library.errorString();
                    errorNumber = ELIBACC;
                }
            }
            consoleLine.append(consoleSide);
        }
        consoleLine.write();
    }
    return errorNumber;
}
