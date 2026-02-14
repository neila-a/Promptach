#include "promptachsettings.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <promptachcommandlineparser.h>

int main(
    int argc, char* argv[]) {
    QGuiApplication a(argc, argv);
    PromptachCommandLineParser parser;
    parser.process(a);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString& locale : uiLanguages) {
        const QString baseName = "PromptachSettings_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //PromptachSettings w;
    //w.show();


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &a, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    Settings settings;
    engine.rootContext()->setContextProperty("settings", &settings);
    engine.load(url);

    return a.exec();
}
