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
        std::string testchara, testGauge, testGaugeBis, testSkills, testSkillsBis, testSpeed;
        int testNbSkills, testTarg;
        testchara = character;

        // TEST ;
        int i, j;
        i = j = 0;
        while (testchara.find(";") != testchara.npos)
        {
            i++;
            testchara = testchara.substr(testchara.find_first_of(';') + 1);
        }
        if (i < 5)
        {
            throw 1;
        }
        testchara = character;

        testchara = testchara.substr(testchara.find_first_of(';') + 1);

        // TEST HP
        testGauge = testchara.substr(0, testchara.find_first_of(';'));
        testGaugeBis = testGauge;
        i = 0;
        while (testGaugeBis.find("/") != testchara.npos)
        {
            i++;
            testGaugeBis = testGaugeBis.substr(testchara.find_first_of('/') + 1);
        }

        if (i != 1)
        {
            throw 2;
        }

        testGaugeBis = testGauge.substr(0, testGauge.find_first_of('/'));
        for (i = 0; i < testGaugeBis.length(); i++)
        {
            if (!isdigit(testGaugeBis[i]))
            {
                throw 2;
            }
        }
        testGaugeBis = testGauge.substr(testGauge.find_first_of('/') + 1);
        for (i = 0; i < testGaugeBis.length(); i++)
        {
            if (!isdigit(testGaugeBis[i]))
            {
                throw 2;
            }
        }

        // TEST MP
        testchara = testchara.substr(testchara.find_first_of(';') + 1);
        testGauge = testchara.substr(0, testchara.find_first_of(';'));
        testGaugeBis = testGauge;
        i = 0;
        while (testGaugeBis.find("/") != testchara.npos)
        {
            i++;
            testGaugeBis = testGaugeBis.substr(testchara.find_first_of('/') + 1);
        }

        if (i != 1)
        {
            throw 3;
        }

        testGaugeBis = testGauge.substr(0, testGauge.find_first_of('/'));
        for (i = 0; i < testGaugeBis.length(); i++)
        {
            if (!isdigit(testGaugeBis[i]))
            {
                throw 3;
            }
        }
        testGaugeBis = testGauge.substr(testGauge.find_first_of('/') + 1);
        for (i = 0; i < testGaugeBis.length(); i++)
        {
            if (!isdigit(testGaugeBis[i]))
            {
                throw 3;
            }
        }

        // TEST Skills
        testchara = testchara.substr(testchara.find_first_of(';') + 1);
        testSkills = testchara.substr(0, testchara.find_first_of(';'));
        for (i = 0; i < testSkills.length(); i++)
        {
            if (!isdigit(testSkills[i]))
            {
                throw 4;
            }
        }
        testNbSkills = std::stoi(testSkills);

        i = 0;
        testSkills = testchara.substr(testchara.find_first_of(';') + 1);
        while (testSkills.find(";") != testchara.npos)
        {
            i++;
            testSkills = testSkills.substr(testSkills.find_first_of(';') + 1);
        }

        if (i != testNbSkills)
        {
            throw 4;
        }

        for (i = 0; i < testNbSkills; i++)
        {
            testchara = testchara.substr(testchara.find_first_of(';') + 1);
            testSkills = testchara.substr(0, testchara.find_first_of(';'));
            testSkillsBis = testSkills;
            j = 0;
            while (testSkillsBis.find("/") != testchara.npos)
            {
                j++;
                testSkillsBis = testSkillsBis.substr(testSkillsBis.find_first_of('/') + 1);
            }
            if (j != 4)
            {
                throw 5;
            }
            for (j = 0; j < 3; j++)
            {
                testSkills = testSkills.substr(testSkills.find_first_of('/') + 1);
                testSkillsBis = testSkills.substr(0, testSkills.find_first_of('/'));
                for (int k = 0; k < testSkillsBis.length(); k++)
                {
                    if (!isdigit(testSkillsBis[k]))
                    {
                        throw 5;
                    }
                }
            }
            testSkills = testSkills.substr(testSkills.find_first_of('/') + 1);
            if (testSkills.length() > 1)
            {
                throw 5;
            }
            if (!isdigit(testSkills[0]))
            {
                throw 5;
            }
            testTarg = std::stoi(testSkills);
            if (testTarg != 1 && testTarg != 0)
            {
                throw 5;
            }
        }

        //TEST Speed
        testchara = testchara.substr(testchara.find_first_of(';') + 1);
        testSpeed = testchara.substr(0, testchara.length() - 1);
        for (i = 0; i < testSpeed.length() - 1; i++)
        {
            if (!isdigit(testSpeed[i]))
            {
		std::cerr << testSpeed << std::endl;
                throw 6;
            }
        }
    }
    catch(int error_code)
    {
        switch (error_code)
        {
            case 1:
                throw std::string("Toutes les donnees n'ont pas ete entrees.");
                //std::cerr << "1" << std::endl;
                break;
            case 2:
                throw std::string("Donnees HP invalides.");
                //std::cerr << "2" << std::endl;
                break;
            case 3:
                throw std::string("Donnees MP invalides.");
                //std::cerr << "3" << std::endl;
                break;
            case 4:
                throw std::string("Nombre de Skills invalide.");
                //std::cerr << "4" << std::endl;
                break;
            case 5:
                throw std::string("Donnees sur l'un des skills invalides.");
                //std::cerr << "5" << std::endl;
                break;
            case 6:
                throw std::string("Donnees de vitesse invalides.");
                //std::cerr << "6" << std::endl;
                break;
            default:
                throw std::string("Donnees du Character invalides!");
                //std::cerr << "Default" << std::endl;
                break;
        }
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

