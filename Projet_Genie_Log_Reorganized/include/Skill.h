#include "../include/Gauge.h"

#ifndef SKILL_H
#define SKILL_H


class Skill                                         // Compétence
{
    public:
    
        //! Constructeur de compétence
        /*! Initialise avec des valeurs par défaut */
        Skill();
    
        //! Constructeur de compétence
        /*!
            \param string représentant la chaine nécessaire à la construction
        */
        Skill(std::string);
    
        //! Destructeur virtuel
        virtual ~Skill();
        
        //! Interface nom de la compétence
        std::string getName();
    
        //! Interface des dégâts de la compétence
        int getDamage();
    
        //! Interface du coût en mana de la compétence
        int getManaCost();
    
        //! Interface de la priorité de la compétence
        int getPriority();
    
        //! Interface de la cible de la compétence
        /*! 0 Ennemi, 1 Allié */
        bool getTarget();
    
        //! Fonction renvoyant si la Compétence est utilisable
        /*! En fonction de la quantité de Mana restante au Character */
        bool available(int);

    protected:

    private:
        std::string name;                           // Nom de la Compétence
        int damage;                                 // Dégâts infligés par la Compétence
        int mana_cost;                              // Coût en Mana de la Compétence
        int priority;                               // Priorité de la Compétence
        bool target;                                // Cible de la Compétence
};

#endif // SKILL_H
