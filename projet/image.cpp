#include "image.h"
#include "database.h"
#include "tag.h"
#include <iostream>

// ??
Image::Image(int idAlbum_v, std::string title_v, std::string path_v, std::string description_v, int position_v, int width_v, int height_v, int pos_x_v, int pos_y_v)
{
    id = createImage(idAlbum_v, title_v, path_v, description_v, position_v, width_v, height_v, pos_x_v, pos_y_v);
    idAlbum  = idAlbum_v;
    position = position_v;
    
    title       = title_v;
    path        = path_v;
    description = description_v;
    
    width    = width_v;
    height   = height_v;
    pos_x    = pos_x_v;
    pos_y    = pos_y_v;
}

// Pour creer une image


//Charger une image
Image::Image(int id_v){
    idAlbum  = getIdAlbumImage(id_v);
    id = id_v;
    title       = getTitleImage(id_v);
    path        = getPathImage(id_v);
    description = getDescriptionImage(id_v);
    position    = getPositionImage(id_v);
    height = getHeightImage(id_v);
    width = getWidthImage(id_v);
    pos_x = getPos_xImage(id_v);
    pos_y = getPos_yImage(id_v);
}


void Image::setDescription(int id, std::string description){ setDescriptionImage(id, description);}
void Image::setTitle(int id, std::string newTitle){               setTitleImage(    id,  newTitle); title = newTitle;}
void Image::setPosition(int id, int newPosition){                 setPositionImage( id,  newPosition); position = newPosition;}
void Image::setHeight(int id, int newHeight){                     setHeightImage(   id,  newHeight); height = newHeight;}
void Image::setWidth(int id, int newWidth){                       setWidthImage(    id,  newWidth); width = newWidth;}
void Image::setPosX(int id, int x){                               setPosXImage(     id,  x); pos_x = x;}
void Image::setPosY(int id, int y){                               setPosYImage(     id,  y); pos_y = y;}

void Image::addTag(int idTag){
    createImagesTags(id,idTag);
}
void Image::addTag(Tag tag){
     createImagesTags(id, tag.getId());
}
void Image::removeTagImage(int idTag){
    removeImagesTagsByTags(idTag);
}
void Image::removeTagImage(Tag tag){
     removeImagesTagsByTags(tag.getId());
}

void Image::remove(int id){ removeImage(id);}

std::vector<int> Image::getTags(){
    return getTagsImagesTags(id);
}
