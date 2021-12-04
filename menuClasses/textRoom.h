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
    const std::list<std::shared_ptr<textRoom>> &getConnectedRooms() const;

    void setConnectedRooms(const std::list<std::shared_ptr<textRoom>> &connectedRooms);

    const std::string &getRoomName() const;

    void setRoomName(const std::string &roomName);

    char *getMyText() const;

    void setMyText1(char *myText);

public:

    std::list<std::shared_ptr<textRoom>> ConnectedRooms;

private:

    std::string roomName;
    char* myText;
};

#endif //VALLENE_TEXTROOM_H
