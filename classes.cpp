#include <iostream>
#include "classes.hpp"
#include <random>

void Character::setName(std::string namec){
    name = namec;
}

std::string Character::getName() const{
    return name;
}

void Character::setHp(int hpn) {
    hp = hpn;
}

int Character::getHp() const{
    return hp;
}

void Character::setXp(int xpn) {
    xp = xpn;
}

int Character::getXp() const{
    return xp;
}

void Character::setStrenght(int strg){
    strength = strg;
}

int Character::getStrenght() const{
    return strength;
}

void Character::setDexterity(int dext){
    dexterity = dext;
}

int Character::getDexterity() const{
    return dexterity;
}

void Character::setConstitution(int cons){
    constitution = cons;
}

int Character::getConstitution() const{
    return constitution;
}

void Character::setIntelligence(int intel){
    intelligence = intel;
}

int Character::getIntelligence() const{
    return intelligence;
}


void Character::setWisdom(int wisd){
    wisdom = wisd;
}

int Character::getWisdom() const{
    return wisdom;
}

void Character::setCharisma(int chr){
    charisma = chr;
}

int Character::getCharisma() const{
    return charisma;
}

void Class::setClassName(std::string name) {
    className = name;
}

std::string Class::getClassName() const{
    return className;
}

void Race::setRaceName(std::string race){
    raceName = race;
}

std::string Race::getRaceName() const{
    return raceName;
}

void Player::setPlayerClass(Class pClass){
    playerClass = pClass;
}

Class Player::getPlayerClass() {
    return playerClass;
}