#include "etudiant1.h"

etudiant1::etudiant1()
{

}

etudiant1 :: etudiant1 ( QString identifiant,QString nom,QString prenom,QString classe)
{
    this->identifiant=identifiant;
    this->nom=nom;
    this->prenom=prenom;
    this->classe=classe;

}

bool etudiant1 ::ajouter()
{
  QSqlQuery query;
  query.prepare("insert into etudiant (identifiant,nom,prenom,classe)values(:identifiant,:nom,:prenom,:classe)");
  //creation des variable liéés
  query.bindValue(":identifiant",identifiant);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":classe",classe);
  return query.exec(); // exec() envoie la requéte pour l'exécuter
}

QSqlQueryModel * etudiant1 :: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etudiant");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));
    return model;

}

bool etudiant1 :: supprimer(QString identifiant)
{
  QSqlQuery query;
  query.prepare("delete from etudiant where identifiant= :identifiant");
   query.bindValue(":identifiant",identifiant);
    return query.exec();
}

bool etudiant1 :: modifier(QString identifiant)
{
    QSqlQuery query;
    query.prepare("update etudiant set  nom= :nom, prenom= :prenom,classe= :classe where identifiant= :identifiant");
    query.bindValue(":identifiant",identifiant);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":classe",classe);
    return query.exec();
}


QSqlQueryModel * etudiant1 :: trier()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etudiant order by identifiant");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));
    return model;


}

QSqlQueryModel * etudiant1 :: trierd()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etudiant order by identifiant desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));
    return model;


}

QSqlQueryModel * etudiant1 :: rechercher(QString classe)
{
    QSqlQuery query;
   // query.prepare("select * from etudiant where classe=:classe");
    //query.bindValue(":classe",classe);
    //query.exec();
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etudiant where classe='2a12'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));
    return model;
}
