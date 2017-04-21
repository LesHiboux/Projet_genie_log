#ifndef INTERFACE_H
#define INTERFACE_H

#include "../include/Map.h"
#include "../include/Character.h"
#include "../include/Gauge.h"
#include "../include/Skill.h"
#include "../include/Game.h"


class Interface
{
    public:
        void affichePerso(Character ); //fini à tester
        void afficheMob(Character ); // fini à tester
        void afficheMap(Map carte); // fini et testé
        void afficheSkill(Character ); //fini à tester
        void afficheCombat(Character , Skill , Character); //fini à tester
        void afficheCombatDetails(Character , Skill , Character , Skill ); //fini à tester
        void afficheWinF(); //fini à tester
        void afficheWinC(Map carte); // fini à tester
        void afficheLoose(); //fini à tester
        void afficheSelectP(Character , Skill ); //fini à tester
};

#endif // INTERFACE_H
