#include <QProcess>
#include "./utils.h"

QString run(
    QString program, QStringList arguments) {
    QProcess process;
    process.setProgram(program);
    process.setArguments(arguments);
    process.start();
    const bool finished = process.waitForFinished();
    return finished ? QString(process.readAllStandardOutput()) : "";
}
