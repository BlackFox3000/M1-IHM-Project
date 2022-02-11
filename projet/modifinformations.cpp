#include "modifinformations.h"
#include "database.h"
#include <QDebug>

//ModifInformations::ModifInformations(QWidget *parent,QString titre,QString extension,QString dimensions,
                                     //QString creation,QString modification,QStringList etiquettes, int idImage,QString img_path) :
ModifInformations::ModifInformations(QWidget *parent,int id_Image):
    QDialog(parent)
{
    setupUi(this);
    this->id_Image = id_Image;
    this->label_titre->setText(getTitleImage(id_Image).c_str());
    this->label_extension->setText("extension");
    this->label_dimensions->setText(getHeightImage(id_Image) + "x" + getWidthImage(id_Image));
    this->label_creation->setText("date creation");
    this->label_modif->setText("date modification");
    //this->comboBox_TagsImage->addItems(etiquettes);
    this->edit_newTitre->setText(getTitleImage(id_Image).c_str());
    //for(int i=0; i<etiquettes.count(); i++){
        //if(comboBox_Tags->findText(etiquettes[i]) == -1){
            //comboBox_Tags->addItem(etiquettes[i]);
        //}
    //}
    actualiserTagsDispos();
    actualiserTagsImage();
    //QPixmap pixmap(img_path);
    //label_apercu->setPixmap(pixmap);
    //label_apercu->setMask(pixmap.mask());
    //imageModif.load(img_path);
    imageModif.load(getPathImage(id_Image).c_str());
    this->label_apercu->setPixmap(QPixmap::fromImage(imageModif).scaled(frame_apercu->width(),frame_apercu->height(),Qt::KeepAspectRatio));
    this->label_apercu->setScaledContents(true);
    this->styleSheet() = parent->styleSheet();
}

void ModifInformations::on_button_valider_Tag_clicked()
{
    //if(comboBox_Tags->findText(editNewTag->text())){
    if(editNewTag->text().trimmed() == ""){
        label_feedback->setText("tag invalide");
    }
    else if(comboBox_Tags->findText(editNewTag->text()) != -1){
        label_feedback->setText("tag deja existant");
    }
    else{
        comboBox_Tags->addItem(editNewTag->text());
        label_feedback->setText("creation d'un nouveau tag");
        std::string str = editNewTag->text().toStdString();
        createTag(str);
        actualiserTagsDispos();
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
    //createImage(1, "proust", "c/moi/bureau", "c'est mon chat en gros la", 1, 100, 100, 0, 0);
    if(edit_newTitre->text().trimmed() == ""){
        label_feedback->setText("Nouveau titre invalide, impossible de valider");
    }
    else{
        //label_titre->setText(edit_newTitre->text());
        //setTitleImage(idImage,edit_newTitre->text().toStdString());
        //setDescriptionImage(idImage,textEdit_description->toPlainText().toStdString());
    }


    accept();
}

void ModifInformations::on_button_annuler_clicked()
{
    //actualiserTagsDispos();
    //actualiserTagsImage();
    //reject();
    //createImagesTags(1,1);
    //createImagesTags(1,2);
    //std::vector<int> ids = getTagsImagesTags(id_Image);
    //qDebug() << ids;
    //qDebug() << "======================================";
    //removeImagesTagsByImage(id_Image);
    //std::vector<int> ids2 = getTagsImagesTags(id_Image);
    //qDebug() << ids2;

    validerTagsImage();

}

void ModifInformations::actualiserTagsDispos()
{
    comboBox_Tags->clear();
    //std::vector<int> ids = getAllTags();
    for(int i : getAllTags()){
        comboBox_Tags->addItem(getTitleTag(i).c_str());
    }
}

void ModifInformations::validerTagsImage(){
    removeImagesTagsByImage(id_Image);
    std::vector<int> ids = getTagsImagesTags(id_Image);

    for(int i=0; i<comboBox_TagsImage->count();i++){
        createImagesTags(id_Image,comboBox_Tags->findText(comboBox_TagsImage->itemText(i))+1);
        //qDebug() << getTitleTag(comboBox_Tags->findText(comboBox_TagsImage->itemText(i))+1).c_str();
    }
    qDebug() << "=======================";
    qDebug() << getTagsImagesTags(id_Image);
    qDebug() << "=======================";
}

void ModifInformations::actualiserTagsImage()
{
    //std::vector<int> ids = getTagsImagesTags(id_Image);
    for(int i : getTagsImagesTags(id_Image)){
        comboBox_TagsImage->addItem(getTitleTag(i).c_str());
    }
}

