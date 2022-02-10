#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include <vector>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

int view();

bool createConnection();

// Albums
int createAlbum(std::string title);

void editAlbum(int id, std::string newTitle);

std::vector<int> getAlbums(); // retourne un tableau d'index des albums existant

std::vector<int> getAllImages(int id);

std::string getTitleAlbum(int id);

void removeAlbum(int id);

// Images
int createImage(int idAlbum, std::string title, std::string path, std::string description, int position, int width, int height, int pos_x, int pos_y);

void setDescriptionImage(int id, std::string newTitle);

int createImage(std::string title_v, std::string path_v);

void setTitleImage(int id, std::string newlTitle);

void setPositionImage(int id, int position);

void setHeightImage(int id, int height);

void setWidthImage(int id, int width);

void setPosXImage(int id, int x);

void setPosYImage(int id, int y);

void removeImage(int id);

void setImageInformation(int id, std::string information);

int getIdAlbumImage(int id);
std::string getTitleImage(int id);
std::string getPathImage(int id);

std::string getDescriptionImage(int id_v);
int getPositionImage(int id_v);
int getHeightImage(int id_v);
int getWidthImage(int id_v);
int getPos_xImage(int id_v);
int getPos_yImage(int id_v);

// Tags
int createTag(std::string title);

void editTag(int id, std::string newTitle);

std::string getTitleTag(int id);

void removeTag(int id);

// ImagesTags
void createImagesTags(int idImage, int idTag);

void removeImagesTagsByImage(int idImage);

void removeImagesTagsByTags(int idTag);

std::vector<int> getAllImages(int id);

std::vector<int> getTagsImagesTags(int id);


#endif // DATABASE_H
