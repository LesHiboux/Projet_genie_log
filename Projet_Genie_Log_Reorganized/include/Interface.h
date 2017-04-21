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
        void afficheMap(Map carte); // fini et test�
        void afficheSkill(Skill );
        void afficheCombat();
        void afficheCombatDetails();
        void afficheWinF();
        void afficheWinC(Map carte); // fini � tester
        void afficheLoose();
        void afficheSelectP();
};

#endif // INTERFACE_H
