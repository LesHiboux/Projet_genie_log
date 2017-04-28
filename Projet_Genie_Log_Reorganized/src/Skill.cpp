#include "../include/Skill.h"

Skill::Skill()
{
    //ctor
    name = "Skill";
    damage = 1;
    mana_cost = 0;
    priority = 0;
    target = 0;
}

Skill::Skill(std::string skill)
{
    //ctor
    name = skill.substr(0, skill.find_first_of('/'));
    skill = skill.substr(skill.find_first_of('/') + 1);
    damage = std::stoi(skill.substr(0, skill.find_first_of('/')));
    skill = skill.substr(skill.find_first_of('/') + 1);
    mana_cost = std::stoi(skill.substr(0, skill.find_first_of('/')));
    skill = skill.substr(skill.find_first_of('/') + 1);
    priority = std::stoi(skill.substr(0, skill.find_first_of('/')));
    skill = skill.substr(skill.find_first_of('/') + 1);
    target = std::stoi(skill.substr(0));
}

Skill::~Skill()
{
    //dtor
}

std::string Skill::getName()
{
    return name;
}

int Skill::getDamage()
{
    return damage;
}

int Skill::getManaCost()
{
    return mana_cost;
}

int Skill::getPriority()
{
    return priority;
}

bool Skill::getTarget()
{
    return target;
}

bool Skill::available(int MP)
{
    return MP >= mana_cost;
}
