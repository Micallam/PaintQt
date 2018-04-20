#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->zmienKolorRed();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->zmienKolorYellow();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->zmienKolorBlue();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->widget->zmienKolorGreen();
}

void MainWindow::on_cleanButton_clicked()
{
    ui->widget->kasujRysunek();
}

void MainWindow::on_actionZapisz_jako_triggered()
{
    QString name=QFileDialog::getSaveFileName(this, "Zapisz", QDir::currentPath(), "Obrazy (*.PNG)");
    ui->widget->zapiszRysunek(name);
}

void MainWindow::on_actionZakoncz_triggered()
{
    QMessageBox::StandardButton requestButton = QMessageBox::question(this,"Uwaga!","Zakończyć działanie aplikacji?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);

    if(requestButton == QMessageBox::Yes)
    {
        QMainWindow::close();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton requestButton = QMessageBox::question(this,"Uwaga!","Zakończyć działanie aplikacji?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);

    if(requestButton == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
