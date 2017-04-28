#include "../include/Map.h"
#include "../include/Character.h"

#ifndef INTERFACE_H
#define INTERFACE_H


class Interface
{
    public:
        void afficheDebutJeu();                             
        void affichePerso(Character);                       
        void afficheMob(Character);                         
        void afficheMap(Map carte);                         
        void afficheSkill(Character);                        
        void afficheCombatDebut(Character, Caracter);       
        void afficheCombat(Character, Character);           
        void afficheCombatDetails(Character, Skill);        
        void afficheWinF();                                 
        void afficheWinC(Map carte);                        
        void afficheLoose();                                
        void afficheSelectP(Character);                     
};

#endif // INTERFACE_H
