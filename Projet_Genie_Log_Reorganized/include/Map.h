#include <iostream>
#include <fstream>
#include <utility>

#ifndef MAP_H
#define MAP_H

class Map
{
	std::pair<int,int> taille;		// Variable contenant les dimensions de la map
	std::pair<int,int> positionJoueur;	// Variable contenant la position du joueur (x,y)
	int** mapEntite;			// Tableau contenant l'emplacement des monstres, des zones de soins, et du point de départ
	int** mapApparence;			// Tableau utilisé pour l'apparence de la map

	public:
		//! Constructeur de map
		/*! Récuperer les informations du fichier map.db pour créer la map */
		Map();
	
		//! Interface du tableau d'entitées
		/*! \return Un tableau des entitées */
		int** getMapEntite();
	
		//! Interface du tableau de decor
		/*! \return Un tableau représentant le decor */
		int** getMapApparence();
	
		//! Interface des dimensions de la map
		/*! \return Une paire représentant la taille de la map <largeur, longueur> */
		std::pair<int,int> getTaille();
	
		//! Interface de la position du joueur
		/*! \return Une paire représentant les coordonnées du personnage <x, y> */
		std::pair<int,int> getPosition();
	
		//! Fonction servant à deplacer le personnage
		/*!
			\param x: Un char représentant la direction du déplacement ('z','q','s' ou 'd')
			\return true: le joueur peut se déplcer dans cette dirrection
			\return false: sinon
		*/
		bool deplacer(char x);
	
		//! Fonction calculant le nombre de monstres restants
		/*! \return Un entier représentant le nombre de monstre restant (à partir du tableau d'entitées) */
		int mobRestants();
	
		//! Fonction indiquant la présence ou non d'un monstre
		/*!
			Se base sur la position du joueur
			\return true: le joueur est sur une case où se situe un monstre
			\return false: sinon
		*/
		bool verif_monstre();
	
		//! Fonction servant à enlever un monstre
		/*! L'enlève du tableau d'entitées */
		void unsetmob();
};
#endif
