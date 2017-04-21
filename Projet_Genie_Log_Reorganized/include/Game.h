#include <stack>
#include <time.h>

#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/Affichage.h"

#ifndef GAME_H
#define GAME_H

class Game
{
	Character joueur;
	Map carte;
	int nbRestant;
	std::stack <Character> pileMob;
	Affichage vue;

	public:
		Game();
		void setPileMob();
		int getNbRestant();
		Character getJoueur();
		bool selection_perso();
		Map getCarte();
			//Fonction gérant le déroulement d'une partie
		void partie();
			//Fonction de combat (joueur vs un monstre)
		bool combat(Character monstre);
			//Fonction pour choisir une compétence d'un joueur
		Skill selectSkillJoueur();
			//Fonction pour choisir une compétence d'un monstre
		Skill selectSkillMonstre(Character monstre);
			//Fonction qui calcul les domages et réduction de mana pour 1 tour et indique si c'est la fin du combat (l'un des deux characters à 0pv)
		bool tour(Skill sortJoueur, Character &monstre, Skill sortMonstre, bool &victoire);
		bool Fin();
};

#endif
