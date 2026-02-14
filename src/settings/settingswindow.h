#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "./ui_settingswindow.h"

#include <QMainWindow>
#include <settings.h>

class SettingsWindow : public QMainWindow {
    Q_OBJECT

public:
    SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void updatePreviewer();

    void on_textsView_clicked(const QModelIndex &index);

    void on_addLine_clicked();
    void on_removeLine_clicked();
    void on_addSide_clicked();
    void on_removeSide_clicked();
    void on_addText_clicked();
    void on_removeText_clicked();
    void on_resetButton_clicked();

    void on_sourceEdit_editingFinished();
    void on_formatEdit_editingFinished();

private:
    Ui::SettingsWindow ui;

    void initTextsView();
    void initFormatEdit();
    void processDisables(int level);

    void recreateConfigWidget();

    QList<int> pos;
    Settings settings;
};

#endif // SETTINGSWINDOW_H
