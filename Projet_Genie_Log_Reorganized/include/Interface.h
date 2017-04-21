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
        void affichePerso(Character );
        void afficheMob(Character );
        void afficheMap(Map carte); // fini et testé
        void afficheSkill(Skill );
        void afficheCombat(Character , Skill , Character);
        void afficheCombatDetails(Character , Skill , Character , Skill );
        void afficheWinF();
        void afficheWinC(Map carte); // fini à tester
        void afficheLoose();
        void afficheSelectP(Character , Skill );
};

#endif // INTERFACE_H
