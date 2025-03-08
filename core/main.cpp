#include <QCoreApplication>
#include <QDir>
#include <QLibrary>
#include <QTime>
#include "./line/consoleline.h"
#include "./line/consoleside.h"
#include <promptachcommandlineparser.h>
#include <settings.h>

typedef coloredText (*textFunction)();

textFunction loadText(
    QString name) {
    QLibrary library(TEXTSDIR + name);
    textFunction _return = (textFunction) library.resolve("entry");
    QString a = library.errorString();
    return _return;
}

int main(
    int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);

    Settings settings;
    textFunction path = loadText(PromptachBuiltInTextsPrefix + QStringLiteral("path"));
    textFunction gitBranch = loadText(PromptachBuiltInTextsPrefix + QStringLiteral("gitBranch"));
    textFunction gitChildPath = loadText(PromptachBuiltInTextsPrefix
                                         + QStringLiteral("gitChildPath"));
    ConsoleSide left = {path(), gitBranch(), gitChildPath()};
    QTime time = QTime::currentTime();
    KConfigGroup generalGroup(&settings, QStringLiteral("General"));
    QString timeFormat = generalGroup.readEntry("timeFormat", "HH:mm");
    ConsoleSide right = {{QDir::home().dirName().trimmed(), USERNAME},
                         {time.toString(timeFormat), TIME}};
    ConsoleLine line = {left, right};

    return line.write();
}
