#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "./ui_promptachsettings.h"

#include <QMainWindow>
#include <settings.h>

class PromptachSettings : public QMainWindow {
    Q_OBJECT

public:
    PromptachSettings(QWidget *parent = nullptr);
    ~PromptachSettings();

private slots:
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
    Ui::PromptachSettings ui;

    void initTextsView();
    void initFormatEdit();

    void recreateConfigWidget();

    QList<int> pos;
    const int locatePreviewer() const;
    Settings settings;
};

#endif // SETTINGSWINDOW_H
