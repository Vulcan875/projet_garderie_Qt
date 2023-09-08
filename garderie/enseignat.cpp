#include "enseignat.h"
#include "ui_enseignat.h"
#include "enseignant.h"
#include <QMessageBox>

enseignat::enseignat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enseignat)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
}

enseignat::~enseignat()
{
    delete ui;
}


void enseignat::on_trier_clicked()
{
    ui->tableView->setModel(e.trier());
}
void enseignat::on_trier_pressed()
{
    ui->tableView->setModel(e.trierd());
}

void enseignat::on_ajouter_clicked()
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



void enseignat::on_pushButton_2_clicked()
{

}

void enseignat::on_modifier_clicked()
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

void enseignat::on_eliminer_clicked()
{
    QString matricule=ui->lineEdit_matricule_2->text();
    bool test=e.supprimer(matricule);
    if(test)
    {   ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectueé\n""click cancel to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("supression non effectueé\n""click cancel to exit."),QMessageBox::Cancel);
}

void enseignat::on_rechercher_clicked()
{
    QString departement=ui->lineEdit_departement_3->text();
    ui->tableView->setModel(e.rechercher(departement));
}
