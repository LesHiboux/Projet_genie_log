#include <iostream>
#include <fstream>
#include <utility>

#ifndef MAP_H
#define MAP_H

class Map
{
	std::pair<int,int> taille;
	std::pair<int,int> positionJoueur;
	int** mapEntite;
	int** mapApparence;

	public:

		Map();
		int** getMapEntite();
		int** getMapApparence();
		std::pair<int,int> getTaille();
		std::pair<int,int> getPosition();
		bool deplacer(char x);
		int mobRestants();
		bool verif_monstre();
		void unsetmob();
};
#endif
