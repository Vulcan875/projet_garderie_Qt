#ifndef ETUDIANT1_H
#define ETUDIANT1_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class etudiant1
{
public:
    //contructeurs
    etudiant1();
    etudiant1(QString,QString,QString,QString);
    //Getters
    QString getmatricule(){return identifiant;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getdepartement(){return classe;}
    //Setters
    void setmatricule(QString m){identifiant=m;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setdepartement(QString d){classe=d;}
    //Foncionnalités de base
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trierd();
    QSqlQueryModel * rechercher(QString);
private:
    QString identifiant,nom, prenom,classe ;
};

#endif // ETUDIANT1_H
