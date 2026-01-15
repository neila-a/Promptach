#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <line/consoleside.h>
#include <settings.h>
#include <texts.h>

extern "C" coloredText entry() {
    const QTime time = QTime::currentTime();
    const Settings settings;
    const KConfigGroup generalGroup(&settings, QStringLiteral("General"));
    const QString timeFormat = generalGroup.readEntry("timeFormat", "HH:mm");
    return {time.toString(timeFormat), TIME};
}

extern "C" void config(
    QWidget *parent, std::function<void()> synced) {
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel *label = new QLabel;
    label->setText(QObject::tr("时间格式"));
    layout->addWidget(label);

    QLineEdit *edit = new QLineEdit;
    const Settings settings;
    const KConfigGroup generalGroup(&settings, "General");
    edit->setText(generalGroup.readEntry("timeFormat", "HH:mm"));
    QObject::connect(edit,
                     &QLineEdit::editingFinished,
                     [edit, generalGroup, synced]() mutable -> void {
                         /*
                          * Reference to outside will cause calling a null pointer and segmentation fault.
                          */
                         Settings lambdaSettings;
                         KConfigGroup lambdaGeneralGroup(&lambdaSettings, "General");

                         const QString text = edit->text();
                         lambdaGeneralGroup.writeEntry("timeFormat", text);
                         lambdaGeneralGroup.config()->sync();
                         synced();
                     });
    layout->addWidget(edit);

    parent->setLayout(layout);
}
