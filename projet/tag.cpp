#include "tag.h"
#include "database.h"
#include <iostream>

//création
Tag::Tag(std::string title_v){
    id    = createTag(title_v);
    title = title_v;
}

//chargement
Tag::Tag(int id_v){
    id    = id_v;
    title = getTitleTag(id_v);
}

int Tag::getId(){
    return id;
}
std::string Tag::getTitle(){
    return title;
}

void Tag::remove(){
    removeTag(id);
}
