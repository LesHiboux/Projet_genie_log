#include "../include/Gauge.h"

#ifndef SKILL_H
#define SKILL_H


class Skill
{
    public:
        Skill();
        Skill(std::string);
        virtual ~Skill();
        std::string getName();
        int getDamage();
        int getManaCost();
        int getPriority();
        bool getTarget();
        bool available(int);

    protected:

    private:
        std::string name;
        int damage;
        int mana_cost;
        int priority;
        bool target;
};

#endif // SKILL_H
