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
    void on_timeFormatEdit_editingFinished();

    void updatePreviewer();

    void on_textsView_clicked(const QModelIndex &index);

    void on_addLine_clicked();
    void on_removeLine_clicked();
    void on_addSide_clicked();
    void on_removeSide_clicked();
    void on_addText_clicked();
    void on_removeText_clicked();

    void on_sourceEdit_editingFinished();

    void on_formatEdit_editingFinished();

private:
    Ui::SettingsWindow ui;

    void initTextsView();
    void initPathAliasTable();
    void initFormatEdit();

    QList<int> pos;
    const int locatePreviewer() const;
    Settings settings;
    bool initing = false;
};

#endif // SETTINGSWINDOW_H
