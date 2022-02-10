#ifndef ALBUM_H
#define ALBUM_H
#include <iostream>
#include <vector>
#include "image.h"

class Album
{
    public:
            int id;
            std::string title;

            //create
            Album(std::string title);
            //load
            Album(int id);

            int getId();
            std::string getTitle();
            //std::vector<Image> getImages();
            std::vector<int> getIdImages();

            void remove();

};

#endif // ALBUM_H
