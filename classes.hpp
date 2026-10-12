#ifndef CLASSES_H
#define CLASSES_H


#include <iostream>
#include <string>
#include <random>


using namespace std;
class Character{
    private:
        std::string name;
        int hp;
        int xp;
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
    
    public:
        void setName(std::string name);
        std::string getName() const;
        void setHp(int hpn);
        int getHp() const;
        void setXp(int xpn);
        int getXp() const;
        void setStrenght(int strg);
        int getStrenght() const;
        void setDexterity(int dext);
        int getDexterity() const;
        void setConstitution(int cons);
        int getConstitution() const;
        void setIntelligence(int intel);
        int getIntelligence() const;
        void setWisdom(int wisd);
        int getWisdom() const;
        void setCharisma(int chr);
        int getCharisma() const;
        

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
    private:
        std::string className;

    public:
        void setClassName(std::string name);
        std::string getClassName() const;

};

class Race{
    private:
        std::string raceName;

    public:
        void setRaceName(std::string race);
        std::string getRaceName() const;

};

class Loot{
    public:
        std::string lootName;
        std::string lootType;
};

class Assistant:Character{
    private:
        std::string name;
};

class Player: Character{
    private:
        Class playerClass;
        Race playerRace;
        Equip Weapon;
        Equip Armor;
        int armorClass;

<<<<<<< HEAD
    public:
        void setPlayerClass(Class pClass);
        Class getPlayerClass();

        Player ();

        void Attack();

        void Defense();
=======
        void Attack() {
            int damage;
            int bonus;
            cout << Name << " usou " << Weapon.Name << " e desferiu um golpe de " << damage << de dano;
        };

        void Defense(){
            if(armorClass > )
            cout << Name << " usou " << Armor.Name << " para se defender\n";
        };
>>>>>>> fcd084ec4801278faa6ac2ae084ca6ccee224ea1
        
};

class Enemy: public Character{
    public:
        Loot itemDrop;
        Equip Weapon;
        Equip Armor;

};

class Minions:Enemy{
    public:
        void Attack();

        void Defense();

};

class Boss: public Enemy{
    public:
        void Attack();

        void Defense();

        void SpecialAttack();
};

#endif