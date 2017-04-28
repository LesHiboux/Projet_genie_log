#include "../include/Map.h"
#include "../include/Character.h"

#ifndef INTERFACE_H
#define INTERFACE_H


class Interface
{
    public:
        void affichePerso(Character);                       //fini à tester
        void afficheMob(Character);                         // fini à tester
        void afficheMap(Map carte);                         // fini et testé
        void afficheSkill(Character);                       //fini à tester
        void afficheCombatDebut(Character, Caracter);       //fini à tester
        void afficheCombat(Character, Character);           //fini à tester
        void afficheCombatDetails(Character, Skill);        //fini à tester
        void afficheWinF();                                 //fini à tester
        void afficheWinC(Map carte);                        // fini à tester
        void afficheLoose();                                //fini à tester
        void afficheSelectP(Character);                     //fini à tester
};

#endif // INTERFACE_H
