#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include "tag.h"
#include <vector>

class Image
{
    public:
        int id;
        int idAlbum;
        std::string title;
        std::string path;
        std::string description;
        int position;
        int width;
        int height;
        int pos_x;
        int pos_y;
    Image(int idAlbum_v, std::string title, std::string path_v, std::string description_v, int position_v, int width_v, int height_v, int pos_x_v, int pos_y_v);
    Image(int id);

    void setDescription(int id, std::string description);
    void setTitle(int id, std::string newTitle);
    void setPosition(int id, int position);
    void setHeight(int id, int height);
    void setWidth(int id, int width);
    void setPosX(int id, int x);
    void setPosY(int id, int y);

    void addTag(int idTag);
    void addTag(Tag tag);
    void removeTagImage(int idTag);
    void removeTagImage(Tag tag);

    std::vector<int> getTags();

    void remove(int id);
};

#endif // IMAGE_H
