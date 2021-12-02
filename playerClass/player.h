//
// Created by Adam on 11/18/2021.
//

#ifndef VALLENE_PLAYER_H
#define VALLENE_PLAYER_H


#include <memory>
#include "../menuClasses/textRoom.h"


class player {
public:

    /* 1 Type of Health*/
    int health;

    /*    STAT SYSTEM BASICS:
     *  Confidence Reflects Summer
     *  Benevolence Reflects Spring
     *  Authority Reflects Winter
     *  Reputation Reflects Autumn
     *
     * */
    int getHealth() const;

    void setHealth(int health);

    int getConfidence() const;

    void setConfidence(int confidence);

    int getBenevolence() const;

    void setBenevolence(int benevolence);

    int getAuthority() const;

    void setAuthority(int authority);

    int getReputation() const;

    void setReputation(int reputation);

    void subtractHealth();

    player();

    player(int, int, int, int);

    std::shared_ptr<textRoom> currentRoom;



private:

    /*    STAT SYSTEM BASICS:
 *  Confidence Reflects Summer
 *  Benevolence Reflects Spring
 *  Authority Reflects Winter
 *  Reputation Reflects Autumn
 *
 * */

    int confidence;
    int benevolence;
    int authority;
    int reputation;

};


#endif //VALLENE_PLAYER_H
