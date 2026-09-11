#ifndef CLASSES_H
#define CLASSES_H

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

class Player: Character{

};

class Boss: Character{
    public:
        int SpecialAttack();
};

#endif