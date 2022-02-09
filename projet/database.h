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

void removeAlbum(int id);


// Images
void createImage(int idAlbum, std::string title, std::string path, std::string description, int position, int width, int height, int pos_x, int pos_y);

void setDescriptionImage(int id, std::string newTitle);

void setTitle(int id, std::string newlTitle);

void setPosition(int id, int position);

void setHeight(int id, int height);

void setWidth(int id, int width);

void setPosX(int id, int x);

void setPosy(int id, int y);

void removeImage(int id);

void setImageInformation(int id, std::string information);

// Tags
void createTag(std::string title);

void editTag(int id, std::string newTitle);

void removeTag(int id);

// ImagesTags
void createImagesTags(int idImage, int idTag);

void removeImagesTagsByImage(int idImage);

void removeImagesTagsByTags(int idTag);
std::vector<int> getAllImages(int id);

#endif // DATABASE_H
