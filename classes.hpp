#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>
#include <string>
#include <random>


using namespace std;
class Character{
    public:
        std::string Name;
        int hp;
        int xp;
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;

        void Attack(){
            cout << "ataque básico";
        };
        void Defense() {
            cout << "defesa";
        };
};

class Dice{
    int faces;

    int rolldice(){

    }
}

class Equip{
    public:
        std::string Name;
        std::string Type;
};

class Class{
    public:
        std::string className;

};

class Race{
    public:
        std::string raceName;

};

class Loot{
    public:
        std::string lootName;
        std::string lootType;
};

class Assistant:Character{

};

class Player: Character{
    public:
        Class playerClass;
        Race playerRace;
        Equip Weapon;
        Equip Armor;
        int armorClass;

        void Attack() {
            int damage;
            int bonus;
            cout << Name << " usou " << Weapon.Name << " e desferiu um golpe de " << damage << de dano;
        };

        void Defense(){
            if(armorClass > )
            cout << Name << " usou " << Armor.Name << " para se defender\n";
        };
        
};

class Enemy: public Character{
    public:
        Loot itemDrop;
        Equip Weapon;
        Equip Armor;

};

class Minions:Enemy{
    public:
        void Attack() {
            cout << Name << " usou " << Weapon.Name << " e desferiu um golpe\n";
        };

        void Defense(){
            cout << Name << " usou " << Armor.Name << " para se defender\n";
        };

};

class Boss: public Enemy{
    public:
        void Attack(){
            cout << Name << " usou " << Weapon.Name << " e desferiu um ataque básico\n";
        };

        void Defense(){
            cout << Name <<" usou " << Armor.Name << "para defender\n";
        };

        void SpecialAttack(){
            cout << Name << "Usou " << Weapon.Name << " e desferiu um ataque avassalador\n";
        };
};

#endif