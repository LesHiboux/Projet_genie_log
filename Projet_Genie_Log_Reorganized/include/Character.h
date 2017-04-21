#include "../include/Skill.h"

#ifndef CHARACTER_H
#define CHARACTER_H


class Character                                     // Personnage - Monstre
{
    public:
        Character();                                // Ctor par défaut
        Character(std::string);                     // Ctor à partir d'un String
        virtual ~Character();                       // Dtor
        std::string getName();                      // Renvoie le nom du Character
        std::pair <int, int> getLife();             // Renvoie la paire <vie/max>
        int getMaxLife();                           // Renvoie le max de Vie
        std::pair <int, int> getMana();             // Renvoie la paire <mana/max>
        int getMaxMana();                           // Renvoie le max de Mana
        int getNbSkills();                          // Renvoie le nb de Compétences
        int getSpeed();                             // Renvoie la Vitesse
        Skill getSkill(int);                        // Renvoie un Skill particulier
        bool isAlive();                             // Renvoie TRUE si le Character est toujours en vie
        bool available(Skill);                      // Renvoie TRUE si le personnage a assez de Mana pour utiliser la Compétence
        void editLife(int);                         // Modifie la Vie en fonction de la valeur donnée (valeur négative pour la restaurer)
        void editMana(int);                         // Modifie la Mana en fonction de la valeur donnée (valeur négative pour la restaurer)

    protected:

    private:
        std::string name;                           // Nom du Character
        Gauge HP;                                   // Jauge de Vie
        Gauge MP;                                   // Jauge de Mana
        int nbSkills;                               // Nombre de Compétences
        Skill* skills;                              // Tableau de Compétences
        int speed;                                  // Vitesse
};

#endif // CHARACTER_H
