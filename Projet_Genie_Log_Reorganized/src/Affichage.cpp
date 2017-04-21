#include "../include/Affichage.h"
#include "../include/Map.h"

void Affichage::affichage_map(Map carte){
	std::cout<<"Monstres restants:"<<carte.mobRestants()<<std::endl;
	int** map=carte.getMapApparence();
	for (int i=0; i<carte.getTaille().first; i++){
		for (int j=0; j<carte.getTaille().second; j++){
			if (i==carte.getPosition().first && j==carte.getPosition().second) std::cout<<"o";
			else
			{
				switch(map[i][j]){
					case 0: std::cout<<".";
						break;
					case 1: std::cout<<"A";
						break;
					case 3: std::cout<<"#";
						break;
					case 9: std::cout<<"~";
						break;
					case 5: std::cout<<"H";
						break;
					case 2: std::cout<<"T";
						break;
					default:
						std::cout<<".";
						break;
				}
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<"Choisissez une direction [z/q/s/d]:"<<std::endl;
}
