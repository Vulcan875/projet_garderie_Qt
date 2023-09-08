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

void MainWindow::on_pushButton_clicked()
{
    QString matricule=ui->lineEdit_matricule->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString departement=ui->lineEdit_departement->text();
    enseignant e(matricule,nom,prenom,departement);
    bool test=e.ajouter();
    if(test)
    {    ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectueé\n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("ajouter non effectueé\n""click cancel to exit."),QMessageBox::Cancel);
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


void MainWindow::on_pushButton_3_clicked()
{
    QString matricule=ui->lineEdit_matricule1->text();
    QString nom=ui->lineEdit_nom1->text();
    QString prenom=ui->lineEdit_prenom1->text();
    QString departement=ui->lineEdit_departement1->text();
    enseignant e(matricule,nom,prenom,departement);
    bool test=e.modifier(matricule);
    if(test)
    {    ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification avec succées \n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("problem de modification \n""click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(e.trier());
}

void MainWindow::on_pushButton_4_pressed()
{
    ui->tableView->setModel(e.trierd());
}

void MainWindow::on_pushButton_5_clicked()
{
    QString departement=ui->lineEdit_departement_3->text();
    ui->tableView->setModel(e.rechercher(departement));
}

void MainWindow::on_pushButton_6_clicked()
{
    etudiant signe_as_student;
    signe_as_student.setModal(true);
    signe_as_student.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    enseignat signe_as_student;
    signe_as_student.setModal(true);
    signe_as_student.exec();
}
