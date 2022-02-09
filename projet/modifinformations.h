#ifndef MODIFINFORMATIONS_H
#define MODIFINFORMATIONS_H

#include "ui_modifinformations.h"

class ModifInformations : public QDialog, private Ui::ModifInformations
{
    Q_OBJECT

public:
    explicit ModifInformations(QWidget *parent = nullptr,QString titre = nullptr,QString extension = nullptr,QString dimensions = nullptr,
                               QString creation = nullptr,QString modification = nullptr,QStringList etiquettes = {""},int idImage = -1);

public:
    int idImage;

private slots:
    void on_button_valider_Tag_clicked();
    //void on_button_validerTitre_clicked();
    void on_button_ajouterTag_clicked();
    void on_button_retirerTag_clicked();
    void on_button_valider_clicked();
    void on_button_annuler_clicked();
};

#endif // MODIFINFORMATIONS_H
