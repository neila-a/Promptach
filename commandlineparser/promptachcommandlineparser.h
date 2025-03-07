#ifndef PROMPTACHCOMMANDLINEPARSER_H
#define PROMPTACHCOMMANDLINEPARSER_H

#include <QCommandLineParser>
#include "PromptachCommandLineParser_global.h"

class PROMPTACHCOMMANDLINEPARSER_EXPORT PromptachCommandLineParser : QCommandLineParser {
public:
    PromptachCommandLineParser();
    void process(QCoreApplication &app);

private:
    QCommandLineOption helpOption = addHelpOption();
    QCommandLineOption versionOption = addVersionOption();
};

#endif // PROMPTACHCOMMANDLINEPARSER_H
