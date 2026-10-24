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
        int strenght;
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

    int rolldice();
};

class Equip{
    private:
        std::string Name;
        std::string Type;
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
        std::string playerClass;
        std::string race;
        Equip Weapon;
        Equip Armor;

    public:

        void setPlayerClass();
        void getPlayerClass();

        void creatPlayer(int n);

        void Attack();

        void SpecialAttack();

        void Defense();
        
};

class Enemy: public Character{
    public:
        Loot itemDrop;
        Equip Weapon;
        Equip Armor;

};

class Minions:Enemy{
    private:
        std::string name;
        std::string enemyType;
        Equip weapon;
    public:
        void Attack();

        void Defense();

};

class Boss: public Enemy{
    private:
        std::string name;
        std::string race;
    public:
        void Attack();

        void Defense();

        void SpecialAttack();
};

class Combat {
    private:
};

#endif