#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEditBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuovo_triggered()
{
    currentFile.clear();
    ui->textEditBox->setText(QString());
}

void MainWindow::on_actionApri_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file",
                                                    QDir::currentPath(),"RTF File (*.rtf)");
    QFile file(fileName);

    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Attenzione",
                             "Non è stato possibile aprire il file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEditBox->setText(text);
    file.close();
}

void MainWindow::on_actionSalva_triggered()
{
    QString fileName;
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Salva",
                                                QDir::currentPath(),"RTF File (*.rtf)");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Attenzione",
                             "Impossibile salvare il file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEditBox->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionSalva_con_nome_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salva con nome",
                                                    QDir::currentPath(),"RTF File (*.rtf)");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Attenzione",
                             "Impossibile salvare il file: " + file.errorString());
        return;
    }

    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEditBox->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionEsci_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if(fontSelected)
        ui->textEditBox->setFont(font);
}

void MainWindow::on_actionGrassetto_triggered()
{
    ui->textEditBox->setFontWeight(QFont::Bold);
}

void MainWindow::on_actionCorsivo_triggered()
{
    ui->textEditBox->setFontItalic(true);
}

void MainWindow::on_actionSottolineato_triggered()
{
    ui->textEditBox->setFontUnderline(true);
}

