#ifndef SUPPRIMERALBUMWINDOW_H
#define SUPPRIMERALBUMWINDOW_H

#include "ui_supprimeralbumwindow.h"

class Supprimeralbumwindow : public QDialog, private Ui::Supprimeralbumwindow
{
    Q_OBJECT

public:
    explicit Supprimeralbumwindow(QWidget *parent = nullptr);
    QString name;
    QList<QString> img_paths;
    int idalbum;
private slots:
    void on_button_anuler_clicked();
    void on_comboBox_albums_currentIndexChanged(int index);
    void actualiserApercu(QString name);
    void on_button_suppr_clicked();
};

#endif // SUPPRIMERALBUMWINDOW_H
