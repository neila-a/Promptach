#ifndef PATHALIASTABLE_H
#define PATHALIASTABLE_H

#include <QWidget>
#include "./ui_pathAliasTable.h"
#include <settings.h>

class PathAliasTable : public QWidget {
    Q_OBJECT
public:
    explicit PathAliasTable(
        std::function<void()> synced, QWidget *parent = nullptr)
        : QWidget{parent} {
        ui.setupUi(this);
        ui.pathAliasesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        initing = true;
        initPathAliasTable();
        initing = false;
        connect(&settings, &Settings::synced, [synced]() -> void { synced(); });
    }

private slots:
    int on_addAlias_clicked();
    void on_removeAlias_clicked();
    void on_pathAliasesTable_itemChanged(QTableWidgetItem *item);
    void on_pathAliasesTable_itemSelectionChanged();

private:
    void initPathAliasTable();
    bool initing = false;
    Ui::centralwidget ui;
    Settings settings;
};

#endif // PATHALIASTABLE_H
