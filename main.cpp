#include <QTime>
#include "./line/consoleline.h"
#include "./line/consoleside.h"
#include "./text/texts.h"
#include "./util/settings.h"
#include "./util/utils.h"

int main(
    int argc, char *argv[]) {
    Settings settings;

    ConsoleSide left = {path(), gitBranch(), gitChildPath()};

    QTime time = QTime::currentTime();
    QString timeFormat = settings.value("timeFormat", "HH:mm").toString();
    ConsoleSide right = {{run("whoami", {}).trimmed(), USERNAME}, {time.toString(timeFormat), TIME}};

    ConsoleLine line = {left, right};
    return line.write();
}
