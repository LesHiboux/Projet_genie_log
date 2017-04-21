#include <stack>
#include <time.h>

#include "../include/Character.h"
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
		/*!
			Constucteur de Game, initialise:
				-Catre: Map
				-nbRestant: nombre de mob à tuer pour gagner
				-plieMob: la pile regroupant tous les mob à tuer
		*/
		Game();

		/*!
			Initialise la pile regroupant les mob
		*/
		void setPileMob();

		/*!
			Initialise la Map
		*/
		Map getCarte();
		
		/*!
			Initialise le Personnage du joueur,
			retourne true si bien initialisé,
			false sinon
		*/
		bool selection_perso();

		/*!
			Récupère le nombre de mob à tuer pour gagner
		*/
		int getNbRestant();

		/*!
			Récupère le joueur
		*/
		Character getJoueur();
		

		
			//Fonction gérant le déroulement d'une partie
		/*!
			Gèrer le déroulement d'une partie
		*/
		void partie();
			//Fonction de combat (joueur vs un monstre)

		/*!
			Gère le combat
			\var Character monstre
				Le monstre
		*/
		bool combat(Character monstre);
			//Fonction pour choisir une compétence d'un joueur

		/*!
			Permet au joueur de choisir son sort
		*/
		Skill selectSkillJoueur();
			//Fonction pour choisir une compétence d'un monstre

		/*!
			Permet au monstre de choisir sa compétence
			\var Character monstre
		*/
		Skill selectSkillMonstre(Character monstre);
			//Fonction qui calcul les domages et réduction de mana pour 1 tour et indique si c'est la fin du combat (l'un des deux characters à 0pv)

		/*!
			Gère un tour:
				-calcul des priorités (le joueur ou le monstre joue en premier)
				-fait le calcul des dommages et la diminution du mana
				-return:
					-true si le combat est fini (l'un des deux character sont mort)
					-false si le combat n'est pas fini

			\var Skill sortJoueur
			\var Character &monstre
			\var Skill sortMonstre
				Le sort du monstre
			\var bool &victoire
				Viérifie si le combat est gagné
		*/
		bool tour(Skill sortJoueur, Character &monstre, Skill sortMonstre, bool &victoire);
};

#endif
