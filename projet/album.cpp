#include "album.h"
#include <iostream>
#include "database.h"

Album::Album(std::string title_v)
{
    title = title_v;
    id = createAlbum(title_v);
    qDebug ("index %d",id);
}

Album::Album(int id_v)
{
    id = id_v;
    title = getTitleAlbum(id);
}

int Album::getId(){
    return id;
}

std::string Album::getTitle(){
    return title;
}

std::vector<int> Album::getIdImages(){
 return getAllImages(id);
}

void Album::remove(){
    removeAlbum(id);
}
