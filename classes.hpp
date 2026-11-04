#ifndef CLASSES_HPP
#define CLASSES_HPP


#include <iostream>
#include <string>
#include <random>


using namespace std;
class Character{
    protected:
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
        void setName(void);
        std::string getName() const;
        void setHp(void);
        int getHp() const;
        void setXp(void);
        int getXp() const;
        void setStrenght(void);
        int getStrenght() const;
        void setDexterity(void);
        int getDexterity() const;
        void setConstitution(void);
        int getConstitution() const;
        void setIntelligence(void);
        int getIntelligence() const;
        void setWisdom(void);
        int getWisdom() const;
        void setCharisma(void);
        int getCharisma() const;
        

        void Attack();
        void Defense();
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
    public:
        void cast_a_spell();
};

class Player: public Character{
    private:
        std::string playerClass;
        std::string race;
        Equip Weapon;
        Equip Armor;

    public:

        void setPlayerClass();
        std::string getPlayerClass() const;

        Player();
        Player createPlayer(void);

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
        int turn;
};

#endif