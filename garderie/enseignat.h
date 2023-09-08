#ifndef ENSEIGNAT_H
#define ENSEIGNAT_H
#include "enseignant.h"


#include <QDialog>

namespace Ui {
class enseignat;
}

class enseignat : public QDialog
{
    Q_OBJECT

public:
    explicit enseignat(QWidget *parent = nullptr);
    ~enseignat();

private slots:
    void on_pushButton_3_clicked();





    void on_pushButton_clicked();

    void on_trier_clicked();

    void on_ajouter_clicked();

    void on_trier_pressed();

    void on_pushButton_2_clicked();

    void on_modifier_clicked();

    void on_eliminer_clicked();

    void on_rechercher_clicked();

private:
    Ui::enseignat *ui;
    enseignant e;
};

#endif // ENSEIGNAT_H
