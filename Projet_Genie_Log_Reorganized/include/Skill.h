#include "../include/Gauge.h"

#ifndef SKILL_H
#define SKILL_H


class Skill                                         // Compétence
{
    public:
        Skill();                                    // Ctor par défaut
        Skill(std::string);                         // Ctor à partir d'un String
        virtual ~Skill();                           // Dtor
        std::string getName();                      // Renvoie le nom de la Compétence
        int getDamage();                            // Renvoie les dégâts infligés par la Compétence
        int getManaCost();                          // Renvoie le coût en Mana de la Compétence
        int getPriority();                          // Renvoie le niveau de Priorité de la Compétence
        bool getTarget();                           // Renvoie la Cible de la Compétence (0 Ennemi, 1 Allié)
        bool available(int);                        // Renvoie si la Compétence est utilisable en fonction de la quantité de Mana restante au Character

    protected:

    private:
        std::string name;                           // Nom de la Compétence
        int damage;                                 // Dégâts infligés par la Compétence
        int mana_cost;                              // Coût en Mana de la Compétence
        int priority;                               // Priorité de la Compétence
        bool target;                                // Cible de la Compétence
};

#endif // SKILL_H
