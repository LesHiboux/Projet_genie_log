#include <stack>
#include <time.h>

#include "../include/Interface.h"

#ifndef GAME_H
#define GAME_H

class Game
{
	Character joueur;			// Le personnage du Joueur
	Map carte;				// La carte sur laquelle il joue
	int nbRestant;				// Le nombre de monstres restants
	std::stack <Character> pileMob;		// La pile contenant les monstres restants
	Interface vue;				// L'affichage de toutes les informations

	public:
		//! Constucteur d'une partie
		/*! initialise:\n
		*		-Catre: Map \n
		*		-nbRestant: int nombre de mob à tuer pour gagner \n
		*		-plieMob: stack<Character> la pile regroupant tous les mob à tuer
		*/

		Game();

		//! Initialise la pile regroupant les mob
		void setPileMob();

		//! Initialise le Personnage du joueur,
		/*!
			\return true si bien initialisé,
			\return false sinon
		*/
		bool selection_perso();

		//! Interface Carte
		/*!
			\return Une Map représentant la cartre du jeux
		*/
		Map getCarte();

		//! Interface nombre de Mob restant
		/*! \return Un entier représentant le nombre de monstre retant à tuer pour gagner */
		int getNbRestant();

		//! Interface Joueur
		/*! \return Un Character représentant le joueur */
		Character getJoueur();

		//! Gèrer le déroulement d'une partie
		void partie();

		//! Gère le combat
		/*!
			\param monstre Le monstre

			\return true: Le combat est gagné (le joueur n'est pas mort)
			\return false: Le combat est perdu (mort du joueur)
		*/
		bool combat(Character monstre, bool &quitter);

		//! Permet au joueur de choisir son sort
		/*!	\param quitter Permet de savoir si le joueur veut quitter le jeux
			\return Skill choisie par le joueur
		*/
		Skill selectSkillJoueur(bool &quitter);

		//! Permet au monstre de choisir sa compétence
		/*!
			\param monstre Le monstre
		*/
		Skill selectSkillMonstre(Character monstre);

		//! Gestion d'un tour
		/*!
			Gère un tour: \n
				-calcul des priorités (le joueur ou le monstre joue en premier) \n
				-fait le calcul des dommages et la diminution du mana

			\param sortJoueur Le sort du joueur
			\param monstre Le monstre
			\param sortMonstre Le sort du monstre
			\param victoire Vérifie si le combat est gagné

			\return true si le combat est fini (l'un des deux Characteur est mort)
			\return false si le combat n'est pas fini
		*/
		bool tour(Skill sortJoueur, Character &monstre, Skill sortMonstre, bool &victoire);
};

#endif
