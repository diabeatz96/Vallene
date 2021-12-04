//
// Created by Adam on 11/28/2021.
//

#include "textRoom.h"

const std::list<std::shared_ptr<textRoom>> &textRoom::getConnectedRooms() const {
    return ConnectedRooms;
}

void textRoom::setConnectedRooms(const std::list<std::shared_ptr<textRoom>> &connectedRooms) {
    ConnectedRooms = connectedRooms;
}

const std::string &textRoom::getRoomName() const {
    return roomName;
}

void textRoom::setRoomName(const std::string &roomName) {
    textRoom::roomName = roomName;
}

void textRoom::setMyText1(char *myText) {
    textRoom::myText = myText;
}

char *textRoom::getMyText() const {
    return myText;
}
