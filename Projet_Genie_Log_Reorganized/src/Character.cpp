#include "../include/Character.h"

Character::Character()
{
    //ctor
    name = "Chara";
    speed = 70;
    nbSkills = 1;
    skills = new Skill[nbSkills];
    skills[0] = Skill();
}

Character::Character(std::string character)
{
    //ctor
    character = character.substr(1);
    try
    {
        std::string testchara, testHP, testMP, testSkills;
        testchara = character;
        int i = 0;
        while (testchara.find(';')
        {
            i++;
            testchara = testchara.substr(testchara.find_fors_of(';'));
        }
        if (i != 5) throw 1;
        testchara = character;
        testchara = testchara.substr(testchara.find_firs_of(';'));
        testHP = testchara.substr(0, character.find_first_of(';'));
        i = 0;
        while (testHP.find('/')
        {
            i++;
            testchara = testchara.substr(testchara.find_fors_of('/'));
        }
        if (i != 1) throw 2;
        testHP = testchara.substr(0, character.find_first_of('/'));
        for (i = 0; i < testHP.length(); i++)
        {
            if (!isdigit(testHP[i])) throw 2;
        }
    }
    catch(int error_code)
    {
        switch (error_code)
            case 1:
                std::cerr << "Toutes les donnees n'ont pas ete entrees." << std::endl;
                break;
            case 2:
                std::cerr << "Donnees HP invalides." << std::endl;
                break;
            case 3:
                std::cerr << "Donnees MP invalides." << std::endl;
                break;
            case 4:
                std::cerr << "Nombre de Skills invalide." << std::endl;
                break;
            case 5:
                std::cerr << "Donnees sur l'un des skills invalides." << std::endl;
                break;
            default:
                std::cerr << "Donnees du Character invalides!" << std::endl;
                break;
    }
    name = character.substr(0, character.find_first_of(';'));
    character = character.substr(character.find_first_of(';') + 1);
    HP = Gauge("Life", character.substr(0, character.find_first_of(';')));
    character = character.substr(character.find_first_of(';') + 1);
    MP = Gauge("Mana", character.substr(0, character.find_first_of(';')));
    character = character.substr(character.find_first_of(';') + 1);
    nbSkills = std::stoi(character.substr(0, character.find_first_of(';')));
    character = character.substr(character.find_first_of(';') + 1);
    skills = new Skill[nbSkills];
    for (int i = 0; i < nbSkills; i++)
    {
        skills[i] = Skill(character.substr(0, character.find_first_of(';')));
        character = character.substr(character.find_first_of(';') + 1);
    }
    speed = std::stoi(character.substr(0, character.length() - 1));
}

Character::~Character()
{
    //dtor
}

std::string Character::getName()
{
    return name;
}

std::pair <int, int> Character::getLife()
{
    return HP.getValMax();
}

int Character::getMaxLife()
{
    return HP.getMax();
}

std::pair <int, int> Character::getMana()
{
    return MP.getValMax();
}

int Character::getMaxMana()
{
    return MP.getMax();
}

int Character::getNbSkills()
{
    return nbSkills;
}

int Character::getSpeed()
{
    return speed;
}

Skill Character::getSkill(int k)
{
    return skills[k - 1];
}

bool Character::isAlive()
{
    return (HP.getVal() > 0);
}

bool Character::available(Skill skill)
{
    return skill.available(MP.getVal());
}

void Character::editLife(int value)
{
    HP.edit(value);
}

void Character::editMana(int value)
{
    MP.edit(value);
}
