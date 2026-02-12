#include "promptachcommandlineparser.h"

PromptachCommandLineParser::PromptachCommandLineParser() {
    setApplicationDescription(_PROJECT_DESCRIPTION);
}

void PromptachCommandLineParser::process(
    QCoreApplication &app) {
    app.setApplicationName(_PROJECT_NAME);
    app.setApplicationVersion(_PROJECT_VERSION);

    QCommandLineParser::process(app);

    if (isSet(helpOption)) {
        showHelp();
        app.quit();
    }
    if (isSet(versionOption)) {
        showVersion();
        app.quit();
    }
}
