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
            Construit à partir d'une string
            \param skill string représentant la chaine nécessaire à la construction
        */
        Skill(std::string skill);
    
        //! Destructeur virtuel de Skill
        virtual ~Skill();
        
        //! Interface nom de la compétence
        /*! \return Une String représentant le nom du skill */
        std::string getName();
    
        //! Interface des dégâts de la compétence
        /*! \return Un rentier représentant la valeur des dommage du skill (si <0 = soin) */
        int getDamage();
    
        //! Interface du coût en mana de la compétence
        /*! \return Un entier représentant le coût en mana de la compétence (<0 = régénération) */
        int getManaCost();
    
        //! Interface de la priorité de la compétence
        /*! \return Un entier représentant la priorité de l'attaque */
        int getPriority();
    
        //! Interface de la cible de la compétence
        /*! 
            \return true: soi-même
            \return false: Ennemi;
         */
        bool getTarget();
    
        //! Fonction renvoyant si la Compétence est utilisable
        /*!
            En fonction de la quantité de Mana restante au Character 
            \return true: Skill utilisable
            \return false: sinon
        */
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
