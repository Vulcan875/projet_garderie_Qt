#include "enseignant.h"

enseignant::enseignant()
{

}
enseignant :: enseignant ( QString matricule,QString nom,QString prenom,QString departement)
{
    this->matricule=matricule;
    this->nom=nom;
    this->prenom=prenom;;
    this->departement=departement;

}

bool enseignant ::ajouter()
{
  QSqlQuery query;
  //convertion chaine character entier

  query.prepare("insert into enseignant (matricule,nom,prenom,departement)values(:matricule,:nom,:prenom,:departement)");
  //creation des variable liéés
  query.bindValue(":matricule",matricule);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":departement",departement);
  return query.exec(); // exec() envoie la requéte pour l'exécuter
}

QSqlQueryModel * enseignant :: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from enseignant");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("departement"));
    return model;

}

bool enseignant :: supprimer(QString matricule)
{
  QSqlQuery query;
  query.prepare("delete from enseignant where matricule= :matricule");
   query.bindValue(":matricule",matricule);
    return query.exec();
}

bool enseignant :: modifier(QString matricule)
{
    QSqlQuery query;
    query.prepare("update enseignant set  nom= :nom, prenom= :prenom,departement= :departement where matricule= :matricule");
    query.bindValue(":matricule",matricule);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":departement",departement);
    return query.exec();
}


QSqlQueryModel * enseignant :: trier()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from enseignant order by matricule");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("departement"));
    return model;


}

QSqlQueryModel * enseignant :: trierd()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from enseignant order by matricule desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("departement"));
    return model;


}

QSqlQueryModel * enseignant :: rechercher(QString departement)
{
    //QSqlQuery query;
    //query.prepare("select * from enseignant where departement=:departement");
    //query.bindValue(":departement",departement);
    //query.exec();
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from enseignant where departement='java'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("departement"));
    return model;
}
