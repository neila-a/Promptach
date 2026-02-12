#ifndef TEXTLOADER_H
#define TEXTLOADER_H

#include <QPluginLoader>
#include <QDir>
#include <QCoreApplication>

class TextLoader : public QPluginLoader {
public:
    TextLoader(const QString text) {
        // prefer to load plugin from this build
        QDir binDir = QDir(QCoreApplication::applicationDirPath());
        binDir.cdUp();
        binDir.cd("lib/qt-6/plugins");
        QCoreApplication::setLibraryPaths(QStringList{ binDir.absolutePath() } + QCoreApplication::libraryPaths());

        setFileName("promptach/texts/" + text);
    }
    ~TextLoader() {}
};

#endif