#include "../include/Skill.h"

#ifndef CHARACTER_H
#define CHARACTER_H


class Character                                     // Personnage - Monstre
{
    public:

        //! Constructeur de Character
        /*! Construit un Character avec des valeurs par défaut */
        Character();                                // Ctor par défaut

        //!Constructeur de Character
        /*!
            Construit un Character à parir d'une string
            \param  character string représentant la chaine nécessaire à la construction
        */
        Character(std::string character);                     // Ctor à partir d'un String

        //!Destructeur de Character
        virtual ~Character();                       // Dtor

        //! Interface du nom du Character
        /*! \return Une string représentant le nom du Character */
        std::string getName();                      // Renvoie le nom du Character

        //! Interface de la vie du Character
        /*! \return Une pair <vieActuelle / vieMax> */
        std::pair <int, int> getLife();             // Renvoie la paire <vie/max>

        //! Interface du maximum de pv du Character
        /*! \return Un entier représentant le maxumum de pv du Character */
        int getMaxLife();                           // Renvoie le max de Vie

        //! Interface du mana du Character
        /*! \return Une pair <manaActuel / manaMax> */
        std::pair <int, int> getMana();             // Renvoie la paire <mana/max>

        //! Interface du mana Max du Character
        /*! \return entier représentant le mana Max du Character */
        int getMaxMana();                           // Renvoie le max de Mana

        //! Interface du nombre de Skill du Character
        /*! \return Un entier représentant le nomre de skill du Character */
        int getNbSkills();                          // Renvoie le nb de Compétences

        //! Interfce de la vitesse du Character
        /*! \return Un entier représentant la vitesse du Character */
        int getSpeed();                             // Renvoie la Vitesse

        //! Interface des skill du Character
        /*!
            Récupère un des Skill du Character à parir d'un tableau
            \param k Un entier représentant le numérot du skill
            \return Un skill représentant le skill choisie
        */
        Skill getSkill(int k);                        // Renvoie un Skill particulier

        //! fonction pour savoir si le Character est mort
        /*! 
            \return true: Le Character est mort
            \return false: sinon
        */
        bool isAlive();                             // Renvoie TRUE si le Character est toujours en vie

        //! fonction pour savoir si le Character peut utiliser un Skill
        /*!
            \return true: il peut uiliser le Skill
            \return false: sinon
        */
        bool available(Skill);                         // Renvoie TRUE si le personnage a assez de Mana pour utiliser la Compétence

        //! fonction permettant de modifier la vie du Character
        /*!
             pvActuels - value
            \param value Un entier représentant un nombre de dommages à appliquer à la vie du personnage ( value<0 = soin)
        */
        void editLife(int value);                         // Modifie la Vie en fonction de la valeur donnée (valeur négative pour la restaurer)

        //! fonction permettant de modifier le mana du Character
        /*!
             manaActuels - value
            \param value Un entier représentant le coût en mana d'un Skill à appliquer au mana du personnage ( value<0 = réganération du mana)
        */
        void editMana(int value);                         // Modifie la Mana en fonction de la valeur donnée (valeur négative pour la restaurer)

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
