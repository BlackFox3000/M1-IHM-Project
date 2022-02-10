#include "modifinformations.h"
#include "database.h"
#include <QDebug>

ModifInformations::ModifInformations(QWidget *parent,QString titre,QString extension,QString dimensions,
                                     QString creation,QString modification,QStringList etiquettes, int idImage,QString img_path) :
    QDialog(parent)
{
    setupUi(this);
    this->idImage = idImage;
    this->label_titre->setText(titre);
    this->label_extension->setText(extension);
    this->label_dimensions->setText(dimensions);
    this->label_creation->setText(creation);
    this->label_modif->setText(modification);
    this->comboBox_listeTags->addItems(etiquettes);
    this->edit_newTitre->setText(titre);
    //this->label_feedback->setText("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    for(int i=0; i<etiquettes.count(); i++){
        //etiquettes.append(comboBox_listeTags->itemText(i));
        if(comboBox_Tags->findText(etiquettes[i]) == -1){
            comboBox_Tags->addItem(etiquettes[i]);
        }
    }
    //QPixmap pixmap(img_path);
    //label_apercu->setPixmap(pixmap);
    //label_apercu->setMask(pixmap.mask());
    //imageModif.load(img_path);
    imageModif.load(img_path);
    this->label_apercu->setPixmap(QPixmap::fromImage(imageModif).scaled(frame_apercu->width(),frame_apercu->height(),Qt::KeepAspectRatio));
    this->label_apercu->setScaledContents(true);

    this->styleSheet() = parent->styleSheet();
    //this->setStyleSheet("QDialog {background : #5b0e2d;}  QTextEdit{border: 2px solid black; width : 16px; height: 12px;} QLabel{color: white;} QPushButton{ background: white; border: 2px solid black; border-radius: 5px; height: 25px; width: 50px;color: black;font-size: 15px;} ");
}

void ModifInformations::on_button_valider_Tag_clicked()
{
    //if(comboBox_Tags->findText(editNewTag->text())){
    if(editNewTag->text().trimmed() == ""){
        qDebug() << "tag invalide";
    }
    else if(comboBox_Tags->findText(editNewTag->text()) != -1){
        qDebug() << "tag deja existant";

    }
    else{
        comboBox_Tags->addItem(editNewTag->text());
        qDebug() << "creation d'un nouveau tag";
    }
}

//INUTILE
/*
void ModifInformations::on_button_validerTitre_clicked()
{
    if(edit_newTitre->text().trimmed() == ""){
        qDebug() << "titre invalide";
    }
    else{
        label_titre->setText(edit_newTitre->text());
        qDebug() << "changement de titre";
    }
}*/


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
        qDebug() << "tag retiré de la photo";
        comboBox_listeTags->removeItem(comboBox_listeTags->findText(comboBox_Tags->currentText())); 
    }
    else{
        qDebug() << "tag non present sur la photo";
    }

}


void ModifInformations::on_button_valider_clicked()
{
    //createImage(1, "proust", "c/moi/bureau", "c'est mon chat en gros la", 1, 100, 100, 0, 0);
    if(edit_newTitre->text().trimmed() == ""){
        label_feedback->setText("Nouveau titre invalide, impossible de valider");
    }
    else{
        //label_titre->setText(edit_newTitre->text());
        setTitleImage(idImage,edit_newTitre->text().toStdString());
        setDescriptionImage(idImage,textEdit_description->toPlainText().toStdString());
        qDebug() << "cool";
    }


    //accept();
}



void ModifInformations::on_button_annuler_clicked()
{
    reject();
}

