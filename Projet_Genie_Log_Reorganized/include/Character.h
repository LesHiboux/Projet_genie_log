#include "../include/Skill.h"

#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    public:
        Character();
        Character(std::string);
        virtual ~Character();
        std::string getName();
        std::pair <int, int> getLife();
        int getMaxLife();
        std::pair <int, int> getMana();
        int getMaxMana();
        int getNbSkills();
        int getSpeed();
        Skill getSkill(int);
        bool isAlive();
        bool available(Skill);
        void editLife(int);
        void editMana(int);

    protected:

    private:
        std::string name;
        Gauge HP;
        Gauge MP;
        int nbSkills;
        Skill* skills;
        int speed;
};

#endif // CHARACTER_H
