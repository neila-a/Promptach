#ifndef TEXTS_H
#define TEXTS_H

#include <QStringList>
#include "../line/consoleside.h"
#include "../util/utils.h"

QString gitParentPath();
coloredText gitChildPath();
coloredText gitBranch();

coloredText path();

#endif // TEXTS_H
