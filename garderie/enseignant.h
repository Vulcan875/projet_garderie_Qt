#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class enseignant
{
public:
    //contructeurs
    enseignant();
    enseignant(QString,QString,QString,QString);
    //Getters
    QString getmatricule(){return matricule;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getdepartement(){return departement;}
    //Setters
    void setmatricule(QString m){matricule=m;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setdepartement(QString d){departement=d;}
    //Foncionnalités de base
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trierd();
    QSqlQueryModel * rechercher(QString);
private:
    QString matricule,nom, prenom,departement ;

};

#endif // ENSEIGNANT_H
