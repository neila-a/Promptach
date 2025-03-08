#include "./texts.h"
#include <settings.h>

extern "C" coloredText entry() {
    const QTime time = QTime::currentTime();
    const Settings settings;
    const KConfigGroup generalGroup(&settings, QStringLiteral("General"));
    const QString timeFormat = generalGroup.readEntry("timeFormat", "HH:mm");
    return {time.toString(timeFormat), TIME};
}
