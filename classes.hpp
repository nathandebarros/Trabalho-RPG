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
        void setName(std::string n);
        std::string getName() const;
        void setHp(int n);
        void setHp(void);
        int getHp() const;
        void setLevel(void);
        void setLevel(int n);
        int getLevel() const;
        void setXp(int n);
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

        void setEquipDefense(int n);

        void setEquipDefense(void);

        int getEquipDefense() const;
        
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

        void uparXp();
        bool uparLevel();

        std::string getArmorType() const;

        void upgradeArmor(int bonus);

        int getArmorDefense() const;

        int Attack();

        std::string specialAttack(std::string n);

        //void Defense();
        
};

class Assistant: public Character{
    public:
        Assistant();
        void cast_a_spell(std::vector<Player>& jogadores, Assistant& x);
};

class Enemy: public Character{
    private:
        Equip weapon;
        Equip armor;

    public: 
        void dropLoot() ;


};

class Minion:public Enemy{

    public:
        Minion();

        void dropLoot(Player &y);

        void specialAttack();



};

class Boss: public Enemy{
    public:
        Boss();

        void dropLoot(Player &y);


        std::string specialAttack(void);
};

#endif