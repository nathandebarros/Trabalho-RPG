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
        int level;
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
        void setLevel(void);
        int getLevel() const;
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

//class Dice{
//    int faces;
//
//    int rolldice();
//};

class Equip{
    protected:
        std::string type;
        std::string name;

    public:
        void setEquipType(std::string t);

        std::string getEquipType() const;
    
        void setEquipName(std::string type);

        std::string getEquipName() const;
        //Equip() = default; 
        
        //Equip(std::string t, const std::vector<std::string>& names);
        
};


class Loot{
    public:
        std::string lootName;
        std::string lootType;
};

class Assistant: public Character{
    public:
        void cast_a_spell();
};

class Player: public Character{
    private:
        std::string playerClass;
        std::string race;
        Equip weapon;
        Equip armor;

    public:
        void setRace(void);

        std::string getRace() const;

        void setPlayerClass();

        std::string getPlayerClass() const;

        Player();
        
        Player::createPlayers(int n);

        void Attack();

        void SpecialAttack();

        void Defense();
        
};

class Enemy: public Character{
    private:
        Equip weapon;
        Equip armor;

    public: 
        Enemy();
        Loot itemDrop();


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
        Player player;
        Enemy enemy;
        Boss boss;

    public: 

    
};

#endif