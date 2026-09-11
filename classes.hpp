#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>
#include <string>


using namespace std;
class Character{
    public:
        int hp;
        int xp;
        int stregth;
        int dexterity;
        int constituition;
        int intelligence;
        int wisdom;
        int charisma;

        int Attack();
        int Defense();
};

class Equip{
    public:
        std::string nome;
        std::string type;
};

class Assistent:Character{

};

class Player: Character{
    public:
        Equip equipamento;
};

class Boss: Character{
    public:
        int SpecialAttack();
};

#endif