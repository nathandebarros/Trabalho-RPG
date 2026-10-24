#include <iostream>
#include "classes.hpp"
#include <random>



void Character::setName(void){
    std::vector<std::string> nameList = {
        "Dian", "Nese", "Falledrick", "Mae", "Valhein", "Dol", "Earl", "Cedria", 
        "Azulei", "Yun", "Cybel", "Ina", "Foolly", "Skili", "Juddol", "Janver", 
        "Viska", "Hirschendy", "Silka", "Hellsturn", "Essa", "Mykonos", "Fenton", 
        "Tyrena", "Inqoul", "Mankov", "Derilia", "Hexema", "Wyton", "Kaedum", 
        "Gouram", "Libertia", "Berasailles", "Juxta", "Tae'hr", "Comtol", "Gherak", 
        "Hest", "Qony", "Masamka", "Twyll", "Tenos", "Axim", "Westrynda", "Saphros", 
        "Olkham", "Handok", "Kemetra", "Yos", "Wentingle", "Ames", "Molosh", "Inkov", 
        "Phasasia", "Ziedinghal", "Bregul", "Eishvack", "Lora", "Krenting", "Symbole", 
        "Elignoir", "Keligkrul", "Qwey", "Vindinglag", "Kusakira", "Weme", "Fayd", 
        "Rushvita", "Vulkor", "Amers", "Ortos", "Vanius", "Chandellia", "Lilikol", 
        "Catca", "Cormus", "Yuela", "Ariban", "Tryton", "Fesscha", "Opalul", "Zakzos", 
        "Hortimer", "Anklos", "Dushasiez", "Polop", "Mektal", "Orinphus", "Denatra", 
        "Elkazzi", "Dyne", "Domos", "Letryal", "Manniv", "Sylestia", "Esnol", "Fasafuros", 
        "Ghanfer", "Kahnite", "Sweyda", "Uylis", "Retenia", "Bassos", "Arkensval", 
        "Impelos", "Grandius", "Fulcrux", "Lassahein", "Edsveda", "Earakun", "Fous", 
        "Maas", "Basenphal", "Jubidya", "Divya", "Kosunten", "Ordayius", "Dozzer", 
        "Gangher", "Escha", "Manchul", "Kempos", "Kulo", "Urtench", "Kesta", "Helahona", 
        "Ryte", "Falcia", "Umannos", "Urkensvall", "Fedra", "Bulkensar", "Comia", 
        "Tyul", "Lasendarl"};

    name = nameList[std::rand()  % nameList.size()];
}

std::string Character::getName() const{
    return name;
}

void Character::setHp(void) {
    hp = (std::rand() % 20) + 1;
}

int Character::getHp() const{
    return hp;
}

void Character::setXp(int xpn) {
    xp = (std::rand() % 20) + 1;
}

int Character::getXp() const{
    return xp;
}

void Character::setStrenght(int strg){
    strenght = (std::rand() % 20) + 1;
}

int Character::getStrenght() const{
    return strenght;
}

void Character::setDexterity(int dext){
    dexterity = (std::rand() % 20) + 1;
}

int Character::getDexterity() const{
    return dexterity;
}

void Character::setConstitution(int cons){
    constitution = (std::rand() % 20) + 1;
}

int Character::getConstitution() const{
    return constitution;
}

void Character::setIntelligence(int intel){
    intelligence = (std::rand() % 20) + 1;
}

int Character::getIntelligence() const{
    return intelligence;
}


void Character::setWisdom(int wisd){
    wisdom = (std::rand() % 20) + 1;
}

int Character::getWisdom() const{
    return wisdom;
}

void Character::setCharisma(int chr){
    charisma = (std::rand() % 20) + 1;
}

int Character::getCharisma() const{
    return charisma;
}

void Class::setClassName(void) {
std::vector<std::string> nameClass = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"};
    className = nameClass[std::rand() % nameClass.size()];
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

void Player::creatPlayer(int n){
    std::vector<Player> players;
    for(int i = 0; i < n; i++){
        Player newPlayer;

        newPlayer= setName();
        newPlayer = setClassName();
        newPlayer = setHp();
        newPlayer = setXp();
        newPlayer = setStrenght();
        newPlayer = setDexterity();
        newPlayer = setConstitution();
        newPlayer = setIntelligence();
        newPlayer = setWisdom();
        newPlayer = setCharisma();

        players.push_back(newPlayer);
    }

    return players;
}