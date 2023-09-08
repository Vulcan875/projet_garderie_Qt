#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "etudiant1.h"

#include <QDialog>

namespace Ui {
class etudiant;
}

class etudiant : public QDialog
{
    Q_OBJECT

public:
    explicit etudiant(QWidget *parent = nullptr);
    ~etudiant();

private slots:
    void on_ajouter_clicked();
    void on_eliminer_clicked();
    void on_modifier_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_2_pressed();
    void on_rechercher_clicked();

private:
    Ui::etudiant *ui;
     etudiant1 e;
};

#endif // ETUDIANT_H
