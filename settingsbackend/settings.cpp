#include "settings.h"
#include <QDir>
#include <QProcessEnvironment>

Settings::Settings(
    KConfig *parent)
    : KConfig("Promptach")
    , QObject() {}

const QString Settings::operator[](
    TextType type) const {
    QString typeNumber = QString::number(type);
    const KConfigGroup formats(this, "format");
    const QString color = formats.readEntry(typeNumber, "38;5;" + typeNumber);
    return color;
}

bool Settings::sync() {
    bool done = KConfig::sync();
    emit synced();
    return done;
}

const TextsList Settings::getTextsList() const {
    const KConfigGroup generalGroup(this, QStringLiteral("General"));
    const TextsList defaultTextsList = {{BuiltInTextsList{"path", "gitBranch", "gitChildPath"},
                                         BuiltInTextsList{"username", "time"}}};

    QByteArray out;
    QDataStream outStream(&out, QIODevice::WriteOnly);
    outStream << defaultTextsList;
    const QByteArray in = generalGroup.readEntry("textsList", out);
    QDataStream inStream(in);
    TextsList got;
    inStream >> got;
    return got;
}

void Settings::modifyTextsList(
    std::function<void(TextsList *list)> modifier) {
    TextsList textsList = getTextsList();
    modifier(&textsList);
    KConfigGroup generalGroup(this, QStringLiteral("General"));

    QByteArray out;
    QDataStream outStream(&out, QIODevice::WriteOnly);
    outStream << textsList;
    generalGroup.writeEntry("textsList", out);
    generalGroup.config()->sync();
}
