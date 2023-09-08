#include "etudiant.h"
#include "ui_etudiant.h"
#include <QMessageBox>
#include "etudiant1.h"


etudiant::etudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etudiant)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
}

etudiant::~etudiant()
{
    delete ui;
}

void etudiant::on_ajouter_clicked()
{
    QString identifiant=ui->lineEdit_identifiant->text();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString classe=ui->lineEdit_classe->text();
    etudiant1 e(identifiant,nom,prenom,classe);
    bool test=e.ajouter();
    if(test)
    {    ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectueé\n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("ajouter non effectueé\n""click cancel to exit."),QMessageBox::Cancel);
}

void etudiant::on_eliminer_clicked()
{
    QString identifiant=ui->lineEdit_identifiant1->text();
    bool test=e.supprimer(identifiant);
    if(test)
    {   ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectueé\n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("supression non effectueé\n""click cancel to exit."),QMessageBox::Cancel);
}

void etudiant::on_modifier_clicked()
{
    QString identifiant=ui->lineEdit_identifiant2->text();
    QString nom=ui->lineEdit_nom2->text();
    QString prenom=ui->lineEdit_prenom2->text();
    QString classe=ui->lineEdit_classe2->text();
    etudiant1 e(identifiant,nom,prenom,classe);
    bool test=e.modifier(identifiant);
    if(test)
    {    ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification avec succées \n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("problem de modification \n""click cancel to exit."),QMessageBox::Cancel);
}

void etudiant::on_pushButton_2_clicked()
{
    ui->tableView->setModel(e.trier());
}

void etudiant::on_pushButton_2_pressed()
{
    ui->tableView->setModel(e.trierd());
}

void etudiant::on_rechercher_clicked()
{
    QString classe=ui->lineEdit_classe3->text();
    ui->tableView->setModel(e.rechercher(classe));
}
