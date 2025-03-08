#include <QCoreApplication>
#include <QDir>
#include <QLibrary>
#include <QTime>
#include "./line/consoleline.h"
#include "./line/consoleside.h"
#include <errno.h>
#include <promptachcommandlineparser.h>
#include <settings.h>

typedef coloredText (*textFunction)();
typedef QList<QList<QStringList>> TextsList;

class BuiltInTextsList : public QStringList {
public:
    BuiltInTextsList(
        std::initializer_list<QString> init) {
        for (const QString &text : init) {
            append(PromptachBuiltInTextsPrefix + text);
        }
    }
};

int main(
    int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);
    int errorNumber = 0;

    const Settings settings;
    const KConfigGroup generalGroup(&settings, QStringLiteral("General"));
    const TextsList defaultTextsList = {{BuiltInTextsList{"path", "gitBranch", "gitChildPath"},
                                         BuiltInTextsList{"username", "time", "ti"}}};
    const TextsList textsList = generalGroup
                                    .readEntry("textsList", QVariant::fromValue(defaultTextsList))
                                    .value<TextsList>();
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
