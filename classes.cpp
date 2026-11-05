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

//          **CRIAÇÃO DOS ATRIBUTOS**
std::string Character::getName() const{
    return name;
}

void Character::setHp(void) {
    hp = (std::rand() % 20) + 1;
}

int Character::getHp() const{
    return hp;
}

void Character::setLevel(void) {
    level = (std::rand() % 20) + 1;
}

int Character::getLevel() const{
    return level;
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

void Player::setRace(void){
    std::vector<std::string>Races = {"Humano", "Elfo", "Ogro", "Anão"};
    race = Races[std::rand() % Races.size()];
}

std::string Player::getRace() const{
    return race;
}

std::string Player::getPlayerClass () const{
    return playerClass;
}

// Setter e Getter de equipamento :
void Equip::setEquipType(std::string t) {
    type = t;
}

std::string Equip::getEquipType(void) const{
    return type;
}

void Equip::setEquipName(std::string type){
    if (type == "Armas Leves"){
        std::vector<string> names = {"Espada Longa", "Machado Grande", "Martelo de Guerra"};
        name = names[std::rand() % names.size()];
    } else if (type == "Armas Leves"){
        std::vector<string> names = {"Adaga", "Espada Curta", "Cimitarra"};
        name = names[std::rand() % names.size()];
    } else if (type == "Armas de Longa Distancia"){
        std::vector<string> names = {"Arco Longo", "Besta"};
        name = names[std::rand() % names.size()];
    } else if (type == "Armas Magicas"){
        std::vector<string> names = {"Cajado", "Simbolo Sagrado", "Varinha"};
        name = names[std::rand() % names.size()];
    }
}

std::string Equip::getEquipName() const {
    return name;
}
//Equip::Equip(std::string t, const std::vector<std::string>& names) : type(t) , name(names.empty() ? "Nenhum" : names[std::rand() % names.size()]) {}

Player::Player() {

    this->setName();
    this->setPlayerClass();
    std::string classe = this->getPlayerClass();
    this->setRace();
    this->setLevel();
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
    if(classe == "Barbarian" || classe == "Paladin" || classe == "Fighter"){
        this->weapon.setEquipType("Armas Marciais");
        std::string tipo = this->weapon.getEquipType();
        if (tipo == "Armas Marcias"){
            this->weapon.setEquipName(tipo);
        }
    } else if (classe == "Monk" || classe == "Rogue"){
        this->weapon.setEquipType("Armas Leves");
        std::string tipo = this->weapon.getEquipType();
        if (tipo == "Armas Leves"){
            this->weapon.setEquipName(tipo);
        }
    } else if (classe == "Ranger"){
        this->weapon.setEquipType("Armas de Longa Distancia");
        std::string tipo = this->weapon.getEquipType();
        if (tipo == "Armas de Longa Distancia"){
            this->weapon.setEquipName(tipo);
        }
    } else{
        this->weapon.setEquipType("Armas Magicas");
        std::string tipo = this->weapon.getEquipType();
        if (tipo == "Armas Magicas"){
            this->weapon.setEquipName(tipo);
        }
    }
    
    
    
        //if (classe == "Barbarian" || classe == "Paladin" || classe == "Fighter"){
        //    this->weapon = Equip("Armas Marcias", {"Espada Longa", "Machado Grande", "Martelo de Guerra",});
        //} else if (classe == "Monk" || classe == "Rogue"){
        //    this->weapon = Equip("Armas Leves", {"Adaga", "Espada Curta", "Cimitarra"});
        //} else if (classe == "Ranger"){
        //    this->weapon = Equip("Armas de Longa Distancia", {"Arco Longo", "Besta"});
        //} else 
        //    this->weapon = Equip("Armas Magicas", {"Cajado", "Simbolo Sagrado", "Varinha"});

}

Player::createPlayers(int n){
    
}

//    **CONSTRUTOR DOS MINIONS**

Enemy::Enemy() {
    this->name = "Morto-Vivo";
    this->setHp();
    this->setLevel();
    this->setStrenght();
    this->strenght = 13;
    this->setDexterity();
    this->dexterity = 6;
    this->setConstitution();
    this->constitution = 16;
    this->setIntelligence();
    this->intelligence = 3;
    this->setWisdom();
    this->wisdom = 6;
    this->setCharisma();
    this->charisma = 5;
}





