#include "modifinformations.h"
#include <QDebug>

ModifInformations::ModifInformations(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->setStyleSheet("QDialog {background : #5b0e2d;}  QTextEdit{border: 2px solid black; width : 16px; height: 12px;} QLabel{color: white;} QPushButton{ background: white; border: 2px solid black; border-radius: 5px; height: 25px; width: 50px;color: black;font-size: 15px;} ");
}

void ModifInformations::on_button_valider_Tag_clicked()
{
    //if(comboBox_Tags->findText(editNewTag->text())){
    if(editNewTag->text().trimmed() == ""){
        qDebug() << "tag invalide";
    }
    else if(comboBox_Tags->findText(editNewTag->text()) != -1){
        qDebug() << "tag deja existant";
        qDebug() << editNewTag->text();
    }
    else{
        comboBox_Tags->addItem(editNewTag->text());
        qDebug() << "creation d'un nouveau tag";
    }
}


void ModifInformations::on_button_validerTitre_clicked()
{
    if(edit_newTitre->text().trimmed() == ""){
        qDebug() << "titre invalide";
    }
    else{
        label_titre->setText(edit_newTitre->text());
        qDebug() << "changement de titre";
    }
}


void ModifInformations::on_button_ajouterTag_clicked()
{
    if(comboBox_listeTags->findText(comboBox_Tags->currentText()) == -1){
        comboBox_listeTags->addItem(comboBox_Tags->currentText());
        qDebug() << "ajout d'un nouveau tag";
    }
    else{
        qDebug() << "tag deja sur l'image";
    }


}


void ModifInformations::on_button_retirerTag_clicked()
{
    if(comboBox_listeTags->findText(comboBox_Tags->currentText()) != -1){
        qDebug() << comboBox_listeTags->findText(comboBox_Tags->currentText());
        qDebug() << "tag retiré de la photo";
        comboBox_listeTags->removeItem(comboBox_listeTags->findText(comboBox_Tags->currentText()));
        qDebug() << comboBox_listeTags->findText(comboBox_Tags->currentText());
    }
    else{
        qDebug() << "tag non present sur la photo";
    }

}

