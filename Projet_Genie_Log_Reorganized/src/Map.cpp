#include "../include/Map.h"

Map::Map()
{
	try
	{
		FormatTest();
	}
	catch (const std::string & err)
	{
		throw err;
	}
	
	int longueur, largeur, tampon;
	std::ifstream fichier("./config/map.db", std::ios::in);

	if (fichier)
	{
		fichier >> longueur >> largeur;
		taille = std::make_pair(longueur,largeur);

		mapEntite=new int*[taille.first];
		for (int i=0; i<taille.first; i++)
		{
			mapEntite[i]=new int[taille.second];
			for (int j=0; j<taille.second; j++)
			{
				fichier >> mapEntite[i][j];
				if (mapEntite[i][j] == 3)
				{
					positionJoueur = std::make_pair(i,j);
				}
			}
		}

		mapApparence=new int*[taille.first];
		for (int i=0; i<taille.first; i++)
		{
			mapApparence[i]=new int[taille.second];
			for (int j=0; j<taille.second; j++)
			{
				fichier >> tampon;
				mapApparence[i][j] = tampon;
			}
		}

		fichier.close();
		std::cout << "Map loaded" << std::endl;
	}
}

void Map::FormatTest()
{
	int longueur, largeur;
	std::string detection="", tampon="";
	std::ifstream fichier("./config/map.db", std::ios::in);
	
	if (fichier)
	{	
		fichier >> tampon >> detection;
		if (isdigit(tampon[0]) && isdigit(detection[0]))
		{
			longueur=stoi(tampon);
			largeur=stoi(detection);
		}
		else
		{
			fichier.close();
			throw std::string("Unexpected map settings, initial variables not clear.");
		}
		tampon=detection="";
		
		while (!fichier.eof())
		{
			fichier >> tampon;
			detection+=tampon;
		}
		if (detection.length()-1!=longueur*largeur*2)
		{
			fichier.close();
			throw std::string("Unexpected map settings, table length not accurate.");
		}
	fichier.close();
	}
	else
	{
		throw std::string("Reading of map.db is impossible");
	}
}
int** Map::getMapEntite()
{
	return mapEntite;
}

int** Map::getMapApparence()
{
	return mapApparence;
}

std::pair<int,int> Map::getTaille()
{
	return taille;
}

std::pair<int,int> Map::getPosition()
{
	return positionJoueur;
}

bool Map::deplacer(char x)
{
	int coordI = positionJoueur.first;
	int coordJ = positionJoueur.second;
	int maxI = taille.first;
	int maxJ = taille.second;

	switch (x)
	{
		case 'z' :
		case 'Z' :

			if (coordI == 0 || mapApparence[coordI-1][coordJ] == 1 || mapApparence[coordI-1][coordJ] == 2 || mapApparence[coordI-1][coordJ] == 9)
			{
				std::cout << "Deplacement impossible" << std::endl;
				return false;
			}
			std::cerr << "la" << std::endl;
			positionJoueur = std::make_pair(coordI-1,coordJ);
			return true;
			break;

		case 'q' :
		case 'Q' :

			if (coordJ == 0 || mapApparence[coordI][coordJ-1] == 1 || mapApparence[coordI][coordJ-1] == 2 || mapApparence[coordI][coordJ-1] == 9)
			{
				std::cout << "Deplacement impossible" << std::endl;
				return false;
			}
			positionJoueur = std::make_pair(coordI,coordJ-1);
			return true;
			break;

		case 's' :
		case 'S' :

			if (coordI == maxI-1 || mapApparence[coordI+1][coordJ] == 1 || mapApparence[coordI+1][coordJ] == 2 || mapApparence[coordI+1][coordJ] == 9)
			{
				std::cout << "Deplacement impossible" << std::endl;
				return false;
			}
			positionJoueur = std::make_pair(coordI+1,coordJ);
			return true;
			break;

		case 'd' :
		case 'D' :

			if (coordJ == maxJ-1 || mapApparence[coordI][coordJ+1] == 1 || mapApparence[coordI][coordJ+1] == 2 || mapApparence[coordI][coordJ+1] == 9)
			{
				std::cout << "Deplacement impossible" << std::endl;
				return false;
			}
			positionJoueur = std::make_pair(coordI,coordJ+1);
			return true;
			break;

		default :

			std::cout << "Entree incorrecte" << std::endl;
			return false;
	}
}

int Map::mobRestants()
{
	int compt=0;
	for (int i=0; i<taille.first; i++)
	{
		for (int j=0; j<taille.second; j++)
		{
			if (mapEntite[i][j]==1)
			{
				compt++;
			}
		}
	}
	return compt;
}

bool Map::verif_monstre()
{
	if (mapEntite[positionJoueur.first][positionJoueur.second] == 1) //numeros d'un mob
	{
		return true;
	}
	return false;
}

void Map::unsetmob()
{
	mapEntite[positionJoueur.first][positionJoueur.second] = 0;
}
