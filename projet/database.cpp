#include <QtWidgets>
#include <QtSql>
#include <vector>
#include "database.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <memory>

void initializeModelImages(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("Images");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("path"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("title"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("position"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("album"));
//! [3]

    model->select();
}

void initializeModelImagesTags(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("ImagesTags");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [2]

//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("image"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("tag"));
//! [3]

    model->select();
}

void initializeModelAlbums(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("Albums");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [2]

//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("title"));
//! [3]

    model->select();
}

void initializeModelTags(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("Tags");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [2]

//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("title"));
//! [3]

    model->select();
}
std::unique_ptr<QTableView> createView(const QString &title, QSqlTableModel *model)
{
//! [4]
    std::unique_ptr<QTableView> view{new QTableView};
    view->setModel(model);
    view->setItemDelegate(new QSqlRelationalDelegate(view.get()));
//! [4]
    view->setWindowTitle(title);
    return view;
}

//static car ne doit pas être appelée plusieurs fois
bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./dbproject.db"); // enregister sur l'ordinateur
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;

    query.exec("create table Images ("
               "id INTEGER PRIMARY KEY, "
               "path varchar(100),"
               "title varchar(20),"
               "description varchar(100),"
               "position int,"
               "album int,"
               "width int,"
               "height int,"
               "pos_x int,"
               "pos_y int,"
               "informations varchar(100)"
               ")");
    if(query.exec("create table Tags (id INTEGER PRIMARY KEY, title varchar(20))")){qDebug()<<"ceeate";}else{qDebug("probleme 3 ");qDebug() << query.lastError().text();};

    query.exec("create table ImagesTags (id INTEGER PRIMARY KEY,"
                                             "image int,"
                                             "tag int"
                                             ")");

    query.exec("create table Albums (id INTEGER PRIMARY KEY, title varchar(20))");
    return true;
}

int view()
{
    QSqlRelationalTableModel modelImages;
    QSqlRelationalTableModel modelImagesTags;
    QSqlRelationalTableModel modelAlbums;
    QSqlRelationalTableModel modelTags;

    initializeModelImages(&modelImages);
    initializeModelImagesTags(&modelImagesTags);
    initializeModelTags(&modelTags);
    initializeModelAlbums(&modelAlbums);

    std::unique_ptr<QTableView> view = createView(QObject::tr("My Relational Table Model"), &modelImagesTags);
    QEventLoop loop;
    view->show();
    loop.exec();

    return 1;
}

// Albums (id , title varchar )
int createAlbum(std::string title){
    QSqlQuery query;
    QString request = QString::fromStdString(title);
    query.prepare("insert into Albums ('title') values('"+request+"')");
    query.exec();
    return query.lastInsertId().toInt();
}

void editAlbum(int id, std::string newTitle){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString newTitleQ = QString::fromStdString(newTitle);
    query.exec("UPDATE Albums SET title = '"+newTitleQ+"' WHERE id="+idQ+";");
}

std::vector<int> getAlbums(){
    QSqlQuery query;
    query.exec("select id from Albums");

    std::vector<int> indexs;
    int field = query.record().indexOf("id");
    while(query.next()){
        std::string idString = query.value(field).toString().toStdString();
        int intIndex = std::stoi(idString);
        indexs.push_back(intIndex);
    }
    return indexs;
}

std::string getTitleAlbum(int id){

    QSqlQuery query;
    query.prepare("select title from Albums where id=?");
    query.addBindValue(id);
    std::string titleString;
    if( query.exec()){

        int field = query.record().indexOf("title");
        while(query.next()){
            titleString = query.value(field).toString().toStdString();
        }

    }

    return titleString;
}

std::vector<int> getAllImages(int id){
    QSqlQuery query;
    query.prepare("select id from Images where album = ?");
    query.addBindValue(id);

    std::vector<int> indexs;
    if( query.exec()){
        int field = query.record().indexOf("id");
        while(query.next()){
            int intIndex = query.value(field).toInt();
            indexs.push_back(intIndex);
        }
     }
    return indexs;
}


void removeAlbum(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM Albums WHERE id='"+idQ+"';");
}


// Images ( id , path varchar, title varchar, description varchar, position int, album int, width int, height int, pos_x int,, pos_y int, information varchar )
int createImage(int idAlbum, std::string title, std::string path, std::string description, int position, int width, int height, int pos_x, int pos_y){
    QSqlQuery query;

    query.prepare("insert into Images ('path','title','description','position','album','width','height','pos_x','pos_y') values (?,?,?,?,?,?,?,?,?)");
    query.addBindValue(path.c_str());
    query.addBindValue(title.c_str());
    query.addBindValue(description.c_str());
    query.addBindValue(position);
    query.addBindValue(idAlbum);
    query.addBindValue(width);
    query.addBindValue(height);
    query.addBindValue(pos_x);
    query.addBindValue(pos_y);
    query.exec();
    return query.lastInsertId().toInt();
}

void setDescriptionImage(int id, std::string description){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString descriptionQ = QString::fromStdString(description);
    query.exec("UPDATE Images SET description = '"+descriptionQ+"' WHERE id="+idQ+";");
}

void setTitleImage(int id, std::string newTitle){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString newTitleQ = QString::fromStdString(newTitle);
    query.exec("UPDATE Images SET title = '"+newTitleQ+"' WHERE id="+idQ+";");
}

void setPositionImage(int id, int position){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString positionQ = QString::number(position);
    query.exec("UPDATE Images SET position = '"+positionQ+"' WHERE id="+idQ+";");
}

void setHeightImage(int id, int height){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString heightQ = QString::number(height);
    query.exec("UPDATE Images SET height = '"+heightQ+"' WHERE id="+idQ+";");
}

void setWidthImage(int id, int width){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString widthQ = QString::number(width);
    query.exec("UPDATE Images SET width = '"+widthQ+"' WHERE id="+idQ+";");
}

void setPosXImage(int id, int x){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString xQ = QString::number(x);
    query.exec("UPDATE Images SET pos_x = '"+xQ+"' WHERE id="+idQ+";");
}

void setPosYImage(int id, int y){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString yQ = QString::number(y);
    query.exec("UPDATE Images SET pos_y = '"+yQ+"' WHERE id="+idQ+";");
}

void removeImage(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM Images WHERE id='"+idQ+"';");
}

void setImageInformation(int id, std::string information){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString informationQ = QString::fromStdString(information);
    query.exec("UPDATE Images SET information = '"+informationQ+"' WHERE id="+idQ+";");
}


int getIdAlbumImage(int id){

    QSqlQuery query;
    query.prepare("select album from Images where id=?");
    query.addBindValue(id);
    int idAlbum;
    if( query.exec()){
        int field = query.record().indexOf("album");
        while(query.next()){
            idAlbum = query.value(field).toInt();
        }
    }
    return idAlbum;
}
std::string getTitleImage(int id){
    QSqlQuery query;
    query.prepare("select title from Images where id=?");
    query.addBindValue(id);
    std::string string;
    if( query.exec()){
        int field = query.record().indexOf("title");
        while(query.next()){
            string = query.value(field).toString().toStdString();
        }
    }

    return string;
}
std::string getPathImage(int id){
    QSqlQuery query;
    query.prepare("select path from Images where id=?");
    query.addBindValue(id);
    std::string string;
    if( query.exec()){
        int field = query.record().indexOf("path");
        while(query.next()){
            string = query.value(field).toString().toStdString();
        }
    }

    return string;
}

std::string getDescriptionImage(int id){
    QSqlQuery query;
    query.prepare("select description from Images where id=?");
    query.addBindValue(id);
    std::string string;
    if( query.exec()){
        int field = query.record().indexOf("description");
        while(query.next()){
            string = query.value(field).toString().toStdString();
        }
    }

    return string;
}

int getPositionImage(int id){

    QSqlQuery query;
    query.prepare("select position from Images where id=?");
    query.addBindValue(id);
    int idAlbum;
    if( query.exec()){
        int field = query.record().indexOf("position");
        while(query.next()){
            idAlbum = query.value(field).toInt();
        }
    }

    return idAlbum;
}

int getWidthImage(int id){

    QSqlQuery query;
    query.prepare("select width from Images where id=?");
    query.addBindValue(id);
    int idAlbum;
    if( query.exec()){
        int field = query.record().indexOf("width");
        while(query.next()){
            idAlbum = query.value(field).toInt();
        }
    }

    return idAlbum;
}

int getHeightImage(int id){

    QSqlQuery query;
    query.prepare("select height from Images where id=?");
    query.addBindValue(id);
    int idAlbum;
    if( query.exec()){
        int field = query.record().indexOf("height");
        while(query.next()){
            idAlbum = query.value(field).toInt();
        }
    }

    return idAlbum;
}

int getPos_xImage(int id){

    QSqlQuery query;
    query.prepare("select pos_x from Images where id=?");
    query.addBindValue(id);
    int idAlbum;
    if( query.exec()){
        int field = query.record().indexOf("pos_x");
        while(query.next()){
            idAlbum = query.value(field).toInt();
        }
    }

    return idAlbum;
}

int getPos_yImage(int id){

    QSqlQuery query;
    query.prepare("select pos_y from Images where id=?");
    query.addBindValue(id);
    int idAlbum;
    if( query.exec()){
        int field = query.record().indexOf("pos_y");
        while(query.next()){
            idAlbum = query.value(field).toInt();
        }
    }
    return idAlbum;
}



// Tags (id, title varchar)
int createTag(std::string title){

    QSqlQuery query;
    query.prepare("insert into Tags ('title') values (?)");
    query.addBindValue(title.c_str());
    query.exec();
    return query.lastInsertId().toInt();
}

//@Not Use
void editTag(int id, std::string newTitle){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString newTitleQ = QString::fromStdString(newTitle);
    query.exec("UPDATE Tags SET title = '"+newTitleQ+"' WHERE id="+idQ+";");
}

std::string getTitleTag(int id){
    QSqlQuery query;
    query.prepare("select title from Tags where id=?");
    query.addBindValue(id);
    std::string string;
    if( query.exec()){

        int field = query.record().indexOf("title");
        while(query.next()){
            string = query.value(field).toString().toStdString();
        }
    }

    return string;
}

void removeTag(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM Tags WHERE id='"+idQ+"';");
}

// ImagesTags (id, image int, tag int)
void createImagesTags(int idImage, int idTag){
    QSqlQuery query;
    query.prepare("insert into ImagesTags ('image','tag') values (?, ?)");
    query.addBindValue(idImage);
    query.addBindValue(idTag);
    query.exec();

}

void removeImagesTagsByImage(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM ImagesTags WHERE image='"+idQ+"';");
}

void removeImagesTagsByTags(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM ImagesTags WHERE tag='"+idQ+"';");
}

std::vector<int> getTagsImagesTags(int id){
    QSqlQuery query;
    query.prepare("select * from ImagesTags where image = ?");
    query.addBindValue(id);


    std::vector<int> indexs;
    if(query.exec()){
        int field = query.record().indexOf("tag");
        while(query.next()){
            int intIndex = query.value(field).toInt();
            indexs.push_back(intIndex);
        }
    }
    return indexs;
}

std::vector<int> getAllTags(){
    QSqlQuery query;
    std::vector<int> indexs;
    if(query.exec("select * from Tags")){
    int field = query.record().indexOf("id");
    while(query.next()){
        int intIndex = query.value(field).toInt();
        indexs.push_back(intIndex);
    }
    }
    return indexs;
}
