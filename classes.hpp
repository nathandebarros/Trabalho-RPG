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
        void setHp(int n);
        void setHp(void);
        int getHp() const;
        void setLevel(void);
        void setLevel(int n);
        int getLevel() const;
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
        

        int Attack();
        int Defense();
};

//class Dice{
//    int faces;
//
//    int rolldice();
//};

class Equip{
    private:
        std::string type;
        std::string name;
        int damage;
        int defense;

    public:

        Equip();

        void setEquipType(std::string t);

        std::string getEquipType() const;
    
        void setEquipName(std::string type);

        std::string getEquipName() const;
        
        void setEquipDamage(std::string name);

        int getEquipDamage() const;

        void setEquipDefense(void);

        int getEquipDefense() const;
        
};


class Loot{
    private:
        std::string lootName;
        std::string lootType;

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

        std::string getWeaponName() const;

        std::string getWeaponType() const;
        
        int getWeaponDamage() const;

        std::string getArmorType() const;

        int getArmorDefense() const;

        int Attack();

        std::string specialAttack(std::string n);

        //void Defense();
        
};

class Assistant{
    public:
        void cast_a_spell(std::vector<Player>& jogadores);
};

class Enemy: public Character{
    private:
        Equip weapon;
        Equip armor;

    public: 
        Loot itemDrop();


};

class Minion:public Enemy{
    private:
        std::string enemyType;
    public:
        Minion();
        void attack();

        void defense();

};

class Boss: public Enemy{
    public:
        Boss();
        void attack();

        void defense();

        std::string specialAttack(void);
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