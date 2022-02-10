#ifndef TAG_H
#define TAG_H
#include <iostream>

class Tag
{
public:
    int id;
    std::string title;

    //création
    Tag(std::string title);
    //chargement
    Tag(int id);

    int getId();
    std::string getTitle();
    void remove();
};

#endif // TAG_H

