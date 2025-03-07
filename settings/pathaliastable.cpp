#include "settingswindow.h"

int SettingsWindow::on_addAlias_clicked() {
    int newRowCount = ui.pathAliasesTable->rowCount() + 1;
    ui.pathAliasesTable->setRowCount(newRowCount);
    return newRowCount - 1; // index = count - 1
}

void SettingsWindow::on_pathAliasesTable_itemChanged(
    QTableWidgetItem *item) {
    if (!initing) {
        KConfigGroup pathAliases(&settings, "pathAliases");
        const QTableWidgetItem *value = ui.pathAliasesTable->item(item->row(), 1);
        const QTableWidgetItem *key = ui.pathAliasesTable->item(item->row(), 0);
        switch (item->column()) {
        // key
        case 0:
            pathAliases.writeEntry(item->text(), value == nullptr ? "" : value->text());
            break;
        // value
        case 1:
            pathAliases.writeEntry(key == nullptr ? "" : key->text(), item->text());
            break;
        }
        pathAliases.config()->sync();
    }
}

void SettingsWindow::on_pathAliasesTable_itemSelectionChanged() {
    const QList<QTableWidgetItem *> selectedItems = ui.pathAliasesTable->selectedItems();
    if (selectedItems.length() != 0)
        qDebug() << selectedItems.at(0)->text();
    ui.removeAlias->setDisabled(selectedItems.length() == 0);
}

void SettingsWindow::on_removeAlias_clicked() {
    const int currentRow = ui.pathAliasesTable->currentRow();

    KConfigGroup pathAliases(&settings, "pathAliases");
    pathAliases.deleteEntry(ui.pathAliasesTable->currentItem()->text());

    ui.pathAliasesTable->removeRow(currentRow);
}
