#include <QCoreApplication>
#include <QDir>
#include <QTime>
#include "./line/consoleline.h"
#include "./line/consoleside.h"
#include "./text/texts.h"
#include <promptachcommandlineparser.h>
#include <settings.h>

int main(
    int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);

    Settings settings;
    ConsoleSide left = {path(), gitBranch(), gitChildPath()};
    QTime time = QTime::currentTime();
    KConfigGroup generalGroup(&settings, QStringLiteral("General"));
    QString timeFormat = generalGroup.readEntry("timeFormat", "HH:mm");
    ConsoleSide right = {{QDir::home().dirName().trimmed(), USERNAME},
                         {time.toString(timeFormat), TIME}};
    ConsoleLine line = {left, right};

    return line.write();
}
