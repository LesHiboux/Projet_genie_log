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
			
			\return true si bien initialisé,
			\return false sinon
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
		
		/*!
			Gèrer le déroulement d'une partie
		*/
		void partie();

		/*!
			Gère le combat
			
			\param monstre Le monstre
			
			\return true: Le combat est gagné (le joueur n'est pas mort)
			\return false: Le combat est perdu (mort du joueur)
		*/
		bool combat(Character monstre);

		/*!
			Permet au joueur de choisir son sort
		*/
		Skill selectSkillJoueur();

		/*!
			Permet au monstre de choisir sa compétence
			\param monstre Le monstre
		*/
		Skill selectSkillMonstre(Character monstre);

		/*!
			Gère un tour:
				-calcul des priorités (le joueur ou le monstre joue en premier)
				-fait le calcul des dommages et la diminution du mana

			\param sortJoueur Le sort du joueur
			\param monstre Le monstre
			\param sortMonstre Le sort du monstre
			\param victoire Viérifie si le combat est gagné

			\return true si le combat est fini (l'un des deux Characteur est mort)
			\return false si le combat n'est pas fini
		*/
		bool tour(Skill sortJoueur, Character &monstre, Skill sortMonstre, bool &victoire);
};

#endif
