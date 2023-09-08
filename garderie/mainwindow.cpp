#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enseignant.h"
#include <QMessageBox>
#include "etudiant.h"
#include "enseignat.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    QString matricule=ui->lineEdit_matricule_2->text();
    bool test=e.supprimer(matricule);
    if(test)
    {   ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectueé\n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("supression non effectueé\n""click cancel to exit."),QMessageBox::Cancel);
}





void MainWindow::on_pushButton_6_clicked()
{
    etudiant signe_as_scolarite;
    signe_as_scolarite.setModal(true);
    signe_as_scolarite.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    enseignat signe_as_rh;
    signe_as_rh.setModal(true);
    signe_as_rh.exec();
}
