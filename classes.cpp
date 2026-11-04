#include <iostream>
#include "classes.hpp"
#include <random>
#include <cstdlib>
#include <ctime>

// ** CRIAÇÃO DE PERSONAGEM **
//    setter e getter usando lista de nomes pre-definidos: 
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

void Character::setXp(void) {
    xp = (std::rand() % 20) + 1;
}

int Character::getXp() const{
    return xp;
}

void Character::setStrenght(void){
    strenght = (std::rand() % 20) + 1;
}

int Character::getStrenght() const{
    return strenght;
}

void Character::setDexterity(void){
    dexterity = (std::rand() % 20) + 1;
}

int Character::getDexterity() const{
    return dexterity;
}

void Character::setConstitution(void){
    constitution = (std::rand() % 20) + 1;
}

int Character::getConstitution() const{
    return constitution;
}

void Character::setIntelligence(void){
    intelligence = (std::rand() % 20) + 1;
}

int Character::getIntelligence() const{
    return intelligence;
}


void Character::setWisdom(void){
    wisdom = (std::rand() % 20) + 1;
}

int Character::getWisdom() const{
    return wisdom;
}

void Character::setCharisma(void){
    charisma = (std::rand() % 20) + 1;
}

int Character::getCharisma() const{
    return charisma;
}

void Player::setPlayerClass(void) {
std::vector<std::string> classList = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"};
    playerClass = classList[std::rand() % classList.size()];
}

std::string Player::getPlayerClass () const{
    return playerClass;
}
Player::Player() {

    this->setName();
    this->setPlayerClass();
    std::string classe = this->getPlayerClass();
    this->setXp();
    this->setHp();
    if (classe ==  "Barbarian" || classe == "Fighter" || classe == "Paladin"){
        this->hp += 5;
        if (this->hp > 20)
        this->hp = 20;
    }
    this->setStrenght();
    if (classe == "Barbarian" || classe == "Fighter" || classe == "Paladin"){
        this->strenght +=5;
        if (this->strenght > 20)
        this->strenght = 20;
    }
    this->setDexterity();
    if (classe == "Rogue" || classe == "Ranger" || classe == "Monk" || classe == "Fighter"){
        this->dexterity += 4;
        if (this->dexterity > 20)
        this->dexterity = 20;
    }
    this->setConstitution();
    if (classe == "Barbarian" || classe == "Fighter"){
        this->constitution += 5;
        if (this->constitution > 20)
        this->constitution = 20;
    }
    this->setIntelligence();
    if (classe == "Wizard"){
        this->intelligence += 5;
        if(this->intelligence > 20)
        this->intelligence = 20;
    
    }
    this->setWisdom();
    if (classe == " Cleric" || classe == "Druid" || classe == "Ranger" || classe == "Monk"){
        this->wisdom += 5;
        if (this->wisdom > 20)
        this->wisdom = 20;
    }
    this->setCharisma();
    if (classe == "Bard" || classe == "Sorcerer" || classe == "Warlock" || classe == "Paladin"){
        this->charisma += 5;
        if (this->charisma > 20)
        this->charisma = 20;
    }

}