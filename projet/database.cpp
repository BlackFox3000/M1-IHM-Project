#include <QtWidgets>
#include <QtSql>
#include <vector>
#include "database.h"
#include <iostream>
#include <string>
#include <memory>

void initializeModelImages(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("Images");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [1]
    model->setRelation(5, QSqlRelation("album", "id", "title"));

//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("title"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("position"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("album"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("path"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("description"));
//! [3]

    model->select();
}

void initializeModelImagesTags(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("ImagesTags");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [1]
    model->setRelation(2, QSqlRelation("Images", "id", "title"));
//! [1] //! [2]
    model->setRelation(3, QSqlRelation("Tags", "id", "name"));
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
//! [1]
//    model->setRelation(2, QSqlRelation("Id", "id", "title"));
//! [1] //! [2]
//    model->setRelation(3, QSqlRelation("Titre", "id", "name"));
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
               " title varchar(20),"
               " description varchar(100)"
               ", position int,"
               "album int,"
               "width int,"
               "height int,"
               "pos_x int,"
               "pos_y int,"
               "informations varchar(100)"
               ")");

    query.exec("create table Tags (id INTEGER PRIMARY KEY, name varchar(20))");

    query.exec("create table ImagesTags (id INTEGER PRIMARY KEY,"
                                             "image int,"
                                             "tag int"
                                             ")");

    query.exec("create table Albums (id INTEGER PRIMARY KEY, title varchar(20))");
    return true;
}

int view()
{
    //Qapp(argc, argv);
//    if (!createConnection())
//        return EXIT_FAILURE;

    //createRelationalTables();

    QSqlRelationalTableModel modelImages;
    QSqlRelationalTableModel modelImagesTags;
    QSqlRelationalTableModel modelAlbums;

    initializeModelImages(&modelImages);
    initializeModelImages(&modelImagesTags);
    initializeModelAlbums(&modelAlbums);

    std::unique_ptr<QTableView> view = createView(QObject::tr("My Relational Table Model"), &modelAlbums);
    QEventLoop loop;
    view->show();
    loop.exec();

    return 1;//app.exec();
}

// Albums (id , title varchar )
void createAlbum(std::string title){
    QSqlQuery query;
    QString request = QString::fromStdString(title);
    query.exec("insert into Albums ('title') values('"+request+"')");
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

    //int * indexs = new int[query.size()];
    std::vector<int> indexs;
    int field = query.record().indexOf("id");
    while(query.next()){
        std::string idString = query.value(field).toString().toStdString();
        int intIndex = std::stoi(idString);
        indexs.push_back(intIndex);
    }
    return indexs;
}

void removeAlbum(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM Albums WHERE id='"+idQ+"';");
}


// Images ( id , path varchar, title varchar, description varchar, position int, album int, width int, height int, pos_x int,, pos_y int, information varchar )
void createImage(int idAlbum, std::string title, std::string path, std::string description, int position, int width, int height, int pos_x, int pos_y){
    QSqlQuery query;
    QString idAlbumQ      = QString::number(idAlbum);
    QString titleQ       = QString::fromStdString(title);
    QString pathQ        = QString::fromStdString(path);
    QString descriptionQ = QString::fromStdString(description);
    QString positionQ    = QString::number(position);
    QString widthQ       = QString::number(width);
    QString heightQ      = QString::number(height);
    QString pos_xQ       = QString::number(pos_x);
    QString pos_yQ       = QString::number(pos_y);
    query.exec("insert into Images ('path','title','description','position','album','width','height','pos_x','pos_y')values('"+
               pathQ        +"','"+
               titleQ       +"','"+
               descriptionQ +"','"+
               positionQ    +"','"+
               idAlbumQ     +"','"+
               widthQ       +"','"+
               heightQ      +"','"
               +pos_xQ      +"','"
               +pos_yQ      +"' )");
}

void setDescriptionImage(int id, std::string description){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString descriptionQ = QString::fromStdString(description);
    query.exec("UPDATE Images SET description = '"+descriptionQ+"' WHERE id="+idQ+";");
}

void setTitle(int id, std::string newTitle){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString newTitleQ = QString::fromStdString(newTitle);
    query.exec("UPDATE Images SET title = '"+newTitleQ+"' WHERE id="+idQ+";");
}

void setPosition(int id, int position){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString positionQ = QString::number(position);
    query.exec("UPDATE Images SET position = '"+positionQ+"' WHERE id="+idQ+";");
}

void setHeight(int id, int height){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString heightQ = QString::number(height);
    query.exec("UPDATE Images SET height = '"+heightQ+"' WHERE id="+idQ+";");
}

void setWidth(int id, int width){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString widthQ = QString::number(width);
    query.exec("UPDATE Images SET width = '"+widthQ+"' WHERE id="+idQ+";");
}

void setPosX(int id, int x){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString xQ = QString::number(x);
    query.exec("UPDATE Images SET pos_x = '"+xQ+"' WHERE id="+idQ+";");
}

void setPosy(int id, int y){
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

// Tags (id, name varchar)
void createTag(std::string title){
    QSqlQuery query;
    QString request = QString::fromStdString(title);
    query.exec("insert into Tags ('title') values('"+request+"')");
}

void editTag(int id, std::string newTitle){
    QSqlQuery query;
    QString idQ = QString::number(id);
    QString newTitleQ = QString::fromStdString(newTitle);
    query.exec("UPDATE Tags SET title = '"+newTitleQ+"' WHERE id="+idQ+";");
}

void removeTag(int id){
    QSqlQuery query;
    QString idQ = QString::number(id);
    query.exec("DELETE FROM Tags WHERE id='"+idQ+"';");
}

// ImagesTags (id, image int, tag int)
void createImagesTags(int idImage, int idTag){
    QSqlQuery query;
    QString idImageQ = QString::number(idImage);
    QString idTagQ = QString::number(idTag);
    query.exec("insert into ImagesTags ('image','tag') values('"+idImageQ+"','"+idTagQ+"')");
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
