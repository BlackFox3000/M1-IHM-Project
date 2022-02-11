#include "modifinformations.h"
#include "database.h"
#include "mainwindow.h"
#include <QDebug>

ModifInformations::ModifInformations(QWidget *parent,int id_Image):
    QDialog(parent)
{
    setupUi(this);
    this->id_Image = id_Image;
    this->label_titre->setText(getTitleImage(id_Image).c_str());
    this->label_extension->setText("extension");
    //this->label_dimensions->setText(getHeightImage(id_Image) + "x" + getWidthImage(id_Image));
    //this->label_dimensions->setText(strcat(getHeightImage(id_Image),"x"));
    this->label_creation->setText("date creation");
    this->label_modif->setText("date modification");
    this->edit_newTitre->setText(getTitleImage(id_Image).c_str());
    this->textEdit_description->setText(getDescriptionImage(id_Image).c_str());
    actualiserTagsDispos();
    actualiserTagsImage();
    imageModif.load(getPathImage(id_Image).c_str());
    this->label_apercu->setPixmap(QPixmap::fromImage(imageModif).scaled(frame_apercu->width(),frame_apercu->height(),Qt::KeepAspectRatio));
    this->label_apercu->setScaledContents(true);
    this->styleSheet() = parent->styleSheet();
}

void ModifInformations::on_button_valider_Tag_clicked()
{
    if(editNewTag->text().trimmed() == ""){
        label_feedback->setText("tag invalide");
    }
    else if(comboBox_Tags->findText(editNewTag->text()) != -1){
        label_feedback->setText("tag deja existant");
    }
    else{
        label_feedback->setText("creation d'un nouveau tag");
        comboBox_Tags->addItem(editNewTag->text());
        std::string str = editNewTag->text().toStdString();
        createTag(str);
        actualiserTagsDispos();
        editNewTag->clear();
    }
}



void ModifInformations::on_button_ajouterTag_clicked()
{
    if(comboBox_TagsImage->findText(comboBox_Tags->currentText()) == -1){
        comboBox_TagsImage->addItem(comboBox_Tags->currentText());
        label_feedback->setText("ajout d'un nouveau tag");
    }
    else{
        label_feedback->setText("tag deja sur l'image");
    }


}


void ModifInformations::on_button_retirerTag_clicked()
{
    if(comboBox_TagsImage->findText(comboBox_Tags->currentText()) != -1){
        label_feedback->setText("tag retiré de la photo");
        comboBox_TagsImage->removeItem(comboBox_TagsImage->findText(comboBox_Tags->currentText()));
    }
    else{
        label_feedback->setText("tag non present sur la photo");
    }

}


void ModifInformations::on_button_valider_clicked()
{
    if(edit_newTitre->text().trimmed() == ""){
        label_feedback->setText("Nouveau titre invalide, impossible de valider");
    }
    else{
        validerTagsImage();
        setTitleImage(id_Image,edit_newTitre->text().toStdString());
        setDescriptionImage(id_Image,textEdit_description->toPlainText().toStdString());

    }
    accept();
}

void ModifInformations::on_button_annuler_clicked()
{
    reject();
}

void ModifInformations::actualiserTagsDispos()
{
    comboBox_Tags->clear();
    for(int i : getAllTags()){
        comboBox_Tags->addItem(getTitleTag(i).c_str());
    }
}

void ModifInformations::validerTagsImage(){
    removeImagesTagsByImage(id_Image);
    std::vector<int> ids = getTagsImagesTags(id_Image);

    for(int i=0; i<comboBox_TagsImage->count();i++){
        createImagesTags(id_Image,comboBox_Tags->findText(comboBox_TagsImage->itemText(i))+1);
    }
}

void ModifInformations::actualiserTagsImage()
{
    for(int i : getTagsImagesTags(id_Image)){
        comboBox_TagsImage->addItem(getTitleTag(i).c_str());
    }
}

