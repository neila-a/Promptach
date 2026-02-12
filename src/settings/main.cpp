#include "settingswindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <promptachcommandlineparser.h>

int main(
    int argc, char *argv[]) {
    QApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "PromptachSettings_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    SettingsWindow w;
    w.show();
    return a.exec();
}
