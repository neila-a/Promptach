#include <QDir>
#include "./utils.h"

QString replaceSymbolLink(
    const QString base, const QString path) {
    QStringList all = path.split(QDir::separator());
    QString nowPath = base;
    for (QString &nowLevel : all) {
        const QDir nowDir(nowPath);
        nowPath += QDir::separator() + nowLevel;
        const QFileInfo nowPathInfo(nowPath);
        const QString nowTarget = nowPathInfo.readSymLink();

        if (nowTarget != "") {
            nowLevel = QString("(%1 → %2)").arg(nowLevel, nowTarget);
        }
    }
    return all.join(QDir::separator());
}
