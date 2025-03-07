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
    int on_addAlias_clicked();

    void on_removeAlias_clicked();

    void on_pathAliasesTable_itemChanged(QTableWidgetItem *item);

    void on_pathAliasesTable_itemSelectionChanged();

    void on_timeFormatEdit_textEdited(const QString &arg1);

    void updatePreviewer();

private:
    Ui::SettingsWindow ui;

    const int locatePreviewer() const;
    Settings settings;
    bool initing = false;
};

#endif // SETTINGSWINDOW_H
