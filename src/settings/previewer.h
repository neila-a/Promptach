#ifndef PREVIEWER_H
#define PREVIEWER_H

#include <QVBoxLayout>
#include <QWidget>

class Previewer : public QWidget {
    Q_OBJECT
public:
    explicit Previewer(QWidget *parent = nullptr);

private:
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
signals:
};

#endif // PREVIEWER_H
