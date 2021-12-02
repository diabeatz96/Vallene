//
// Created by Adam on 11/28/2021.
//

#ifndef VALLENE_TEXTROOM_H
#define VALLENE_TEXTROOM_H

#include "raylib.h"
#include <string>
#include <list>
#include <memory>

class textRoom {

public:

    std::list<std::shared_ptr<textRoom>> ConnectedRooms;

private:

    std::string roomName;
    std::string myText;
};


#endif //VALLENE_TEXTROOM_H
