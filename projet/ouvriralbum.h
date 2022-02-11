#ifndef OUVRIRALBUM_H
#define OUVRIRALBUM_H

#include "ui_ouvriralbum.h"

class OuvrirAlbum : public QDialog, private Ui::OuvrirAlbum
{
    Q_OBJECT

public:
    explicit OuvrirAlbum(QWidget *parent = nullptr);
    Ui::OuvrirAlbum *ui_ouvrirAlbum;
    QString name;
    QList<QString> img_paths;
    int idalbum;

private slots:
    void on_button_ouverture_clicked();
    void on_button_anuler_clicked();
    void on_comboBox_albums_currentIndexChanged(int index);
    void actualiserApercu(int idAlbum);
};

#endif // OUVRIRALBUM_H
