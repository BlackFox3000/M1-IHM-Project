#include "navigation.h"
#include "ui_navigation.h"
#include <QtWidgets>

navigation::navigation(QWidget *parent)
   : QWidget(parent)
{
  // nomImage.append("gtazz.lul");
  // nomImage.append("lol.png");
   setupUi(this);
  // pix.load(":/gtazz.jpg");
  // listpix.append(pix);
 //  pix.load(":/lol.png");
 //  listpix.append(pix);



}

   void navigation::on_butonD_clicked() {
       int somme = lcdNumber->intValue()+1;
       if(lcdNumber->intValue()==listpix.size()){
           lcdNumber->display(1);
       }
       else{
       lcdNumber->display(somme);
       }
       on_Go_clicked();



   }
   void navigation::on_butonG_clicked() {
       int somme = lcdNumber->value()-1;
       if(lcdNumber->intValue()==1){
          lcdNumber->display(listpix.size());
       }
       else{
       lcdNumber->display(somme);
       }
       on_Go_clicked();

   }
   void navigation::on_Go_clicked(){

       int number = lcdNumber->value();


       emit  putImage(listpix.at(number-1));
       nomImagetest = nomImage.at(number-1);
       if(nomImagetest.contains(".jpg") || nomImagetest.contains(".png")){
       nomImagetest = nomImagetest.remove(nomImagetest.indexOf('.'),4);}
       name->setText(nomImagetest);
   }

   navigation::~navigation()
   {
   }


