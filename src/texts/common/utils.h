#ifndef UTILS_H
#define UTILS_H

#include <QStringList>

QString run(const QString program, const QStringList arguments);
QString replaceSymbolLink(const QString base, const QString path);
/*
    QStringList all = QDir::currentPath().trimmed().split(QDir::separator());
    qsizetype gitTopLevel = run("git", {"rev-parse", "--show-toplevel"})
                                .replace("\n", "")
                                .split(QDir::separator())
                                .length();*/
bool isInGit();

#endif // UTILS_H
