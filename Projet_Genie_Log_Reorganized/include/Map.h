#include <iostream>
#include <fstream>
#include <utility>

#ifndef MAP_H
#define MAP_H

class Map
{
	std::pair<int,int> taille;	/*!< Variable contenant les dimensions de la map */
	std::pair<int,int> positionJoueur;	/*!< Variable contenant la position du joueur (x,y) */
	int** mapEntite;	/*!< Tableau contenant l'emplacement des monstres, des zones de soins, et du point de départ */
	int** mapApparence;	/*!< Tableau utilisé pour l'apparence de la map */

	public:
		//*! Constructeur de map
		/*! Récuperer les informations du fichier map.db pour créer la map */
		Map();
	
		//*! Interface du tableau d'entitées
		/*! Retourne le tableau des entitées */
		int** getMapEntite();
	
		//*! Interface du tableau de decor
		/*! Retourne le tableau représentant le decor */
		int** getMapApparence();
	
		//*! Interface des dimensions de la map
		/*! Retourne une paire représentant la taille de la map <largeur, longueur> */
		std::pair<int,int> getTaille();
	
		//*! Interface de la position du joueur
		/*! Retourne une paire représentant les coordonnées du personnage <x, y> */
		std::pair<int,int> getPosition();
	
		//*! Fonction servant à deplacer le personnage
		/*!
			/parametre x: un char représentant la direction du déplacement ('z','q','s' ou 'd')
		*/
		bool deplacer(char x);
	
		//*! Fonction ressortant le nombre de monstres restants
		/*! Calculé à partir du tableau d'entitées */
		int mobRestants();
	
		//*! Fonction indiquant la présence ou non d'un monstre
		/*! Se base sur la position du joueur */
		bool verif_monstre();
	
		//*! Fonction servant à enlever un monstre
		/*! L'enlève du tableau d'entitées */
		void unsetmob();
};
#endif
