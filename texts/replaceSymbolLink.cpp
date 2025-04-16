#include <QDir>
#include "./utils.h"

QString replaceSymbolLink(
    const QString base, const QString path) {
    QStringList all = path.split(QDir::separator());
    QString nowPath = base;
    for (QString &nowLevel : all) {
        QDir nowDir(nowPath);
        nowPath += QDir::separator() + nowLevel;
        const QString nowTarget = nowDir.relativeFilePath(QFile::symLinkTarget(nowPath));
        if (nowTarget != "") {
            nowLevel = QString("(%1 → %2)").arg(nowLevel, nowTarget);
        }
    }
    return all.join(QDir::separator());
}
