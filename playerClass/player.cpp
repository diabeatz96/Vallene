//
// Created by Adam on 11/18/2021.
//

#include "player.h"

int player::getHealth() const {
    return health;
}

void player::setHealth(int health) {
    player::health = health;
}

int player::getConfidence() const {
    return confidence;
}

void player::setConfidence(int confidence) {
    player::confidence = confidence;
}

int player::getBenevolence() const {
    return benevolence;
}

void player::setBenevolence(int benevolence) {
    player::benevolence = benevolence;
}

int player::getAuthority() const {
    return authority;
}

void player::setAuthority(int authority) {
    player::authority = authority;
}

int player::getReputation() const {
    return reputation;
}

void player::setReputation(int reputation) {
    player::reputation = reputation;
}

void player::subtractHealth() {
    health--;
}

/**
 * If player chooses basic stats we can take basic constructor, if not we can make player choose.
 */

player::player() {
    health = 5;
    confidence = 10;
    benevolence = 10;
    authority = 10;
    reputation = 10;
}

player::player(int iconfidence, int ibenevolence, int iauthority, int ireputation) {

    health = 5;
    confidence = iconfidence;
    benevolence = ibenevolence;
    authority = iauthority;
    reputation = ireputation;

}
