#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuovo_triggered();

    void on_actionApri_triggered();

    void on_actionSalva_triggered();

    void on_actionSalva_con_nome_triggered();

    void on_actionEsci_triggered();

    void on_actionFont_triggered();

    void on_actionGrassetto_triggered();

    void on_actionCorsivo_triggered();

    void on_actionSottolineato_triggered();

private:
    Ui::MainWindow *ui;

    QString currentFile = "";
};
#endif // MAINWINDOW_H
