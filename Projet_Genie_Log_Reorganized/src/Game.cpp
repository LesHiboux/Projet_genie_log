#include "../include/Game.h"

	/************************
	Constructeurs, get et set
	************************/

//test

Game::Game() {
	carte=Map();
	nbRestant=carte.mobRestants();
	setPileMob();
}

int Game::getNbRestant()
{
	return nbRestant;
}

Character Game::getJoueur()
{
	return joueur;
}

Map Game::getCarte()
{
	return carte;
}

void Game::setPileMob()
{
	std::fstream mobFile;
	mobFile.open("./config/monstres.db", std::fstream::in);
	if (mobFile.is_open())
	{
		Character mobTmp;
		std::string characterString;
		for (int i=0; i<nbRestant; i++)
		{
			getline(mobFile, characterString);

			//std::cerr << characterString << std::endl;
			Character mobTmp(characterString);
			pileMob.push(mobTmp);
		}
		mobFile.close();
	}
	else
	{
		std::cerr << "Lecture du fichier monstres impossible" << std::endl;
	}
}


	/********************
	Fin constru, get, set
	********************/

	/********************
	  Déroulement Partie
	*********************/

	void Game::partie()
	{
		bool victoire=false;
		bool finPartie=false;
		if(!selection_perso()) return;
			//Variable pour choisir une direction ou aller sur la carte
		std::string direction;
		while (finPartie==false)
		{
			//vue.afficheMap();
				//On se déplace tant qu'on ne rencontre pas de monstre
			while (carte.verif_monstre()!=true)
			{
				vue.afficheMap(carte);
				std::cin >> direction;
				if (direction=="quitter") {
					std::cout<<"Merci d'avoir joué!"<<std::endl;
					return;
				}
				while(!carte.deplacer(direction[0]))
				{
					std::cerr << "Choisissez une direction" << std::endl;
					std::cin >> direction;
					if (direction=="quitter") {
						std::cout<<"Merci d'avoir joué!"<<std::endl;
						return;
					}
				}
				/*while (direction!="z" || direction!="Z" || direction!="q" || direction!="Q" || direction!="s" || direction!="S" || direction!="d" || direction!="D")
				{
					cerr<<"Choisissez une direction"<<endl;
					cin>> direction;
				}*/
			}
			Character monstre=pileMob.top();
			pileMob.pop();
			carte.unsetmob();
			victoire=combat(monstre);
			if (victoire)
			{
					//Afficher victoire combat
				vue.afficheWinC(carte);
				nbRestant--;
				if (nbRestant<=0) finPartie=true;
			}
			else
			{
					//Affiche perdu...
				vue.afficheLoose();
				//std::cerr<<"you died..."<<std::endl;
				return;
				//Afficher you died
			}
		}
		vue.afficheWinF();
		//Afficher victoire totale!!!
	}

bool Game::selection_perso() {
	std::ifstream liste_persos("./config/liste_persos.db");
	if(liste_persos){
		std::string perso;
		std::string choix;
		getline(liste_persos, perso);
		while (!liste_persos.eof()){
			joueur = Character(perso);
				//affichage_selection_perso;
			vue.afficheSelectP(joueur);
			//std::cerr << joueur.getName() << std::endl;
			//std::cerr << "o: joueur | n: suivant" << std::endl;
			std::cin >> choix;
			if (choix=="quitter") {
				std::cout<<"Merci d'avoir joué!"<<std::endl;
				return false;
			}
			else {
				while (choix!="o" && choix!="n") {
					std::cout << "erreur entrez o ou n" << std::endl;
					std::cin >> choix;
				}
 				if (choix=="o") return true;
				getline(liste_persos, perso);
			}
		}
		liste_persos.close();
		return selection_perso();
	}
	else std::cerr << "Impossible d'ouvrir le fichier" << std::endl;
	return false;
}

	/********************
		   combat
	********************/
bool Game::combat(Character monstre)
{
	bool victoire = false;		//dit si on as gagnés
	bool finCombat=false;		//dit si c'est la fin du combat
		//bool pour savoir si le joueur veux quitter
	bool quitter=false;
	while (finCombat!=true)
	{
			//au départ, on affiche les infos du mob et du joueur + compétences du joueur
		//vue.afficheMob(monstre);
		//vue.affichePerso(joueur);
		vue.afficheCombat(joueur, monstre);
		Skill sortJoueur, sortMonstre;
		sortJoueur=selectSkillJoueur(quitter);
		if (quitter==true) return victoire;
		//std::cerr<<sortJoueur.getName()<<", "<<sortJoueur.getDamage()<<", "<<joueur.getLife().first<<std::endl;
		sortMonstre=selectSkillMonstre(monstre);
		//std::cerr<<sortMonstre.getName()<<", "<<sortMonstre.getDamage()<<", "<<monstre.getLife().first<<std::endl;
		finCombat=tour(sortJoueur, monstre, sortMonstre, victoire);
	}
	//std::cerr<<victoire<<std::endl;
	return victoire;
}

Skill Game::selectSkillJoueur(bool &quitter)
{
	bool done=false; //vérifie si la compétence a bien été choisie
	Skill sort;
	//std::cerr << "sélectionnez une compétence" << std::endl;
	while (done!=true)
	{
		std::string select;	//faire des sélections
		std::cin >> select;
		if (select=="quitter") {
			std::cout<<"Merci d'avoir joué!"<<std::endl;
			done=true;
			quitter=true;
			sort=Skill();
		}
		else {
			int select_skill=std::stoi(select);
			while ( select_skill<=0 || select_skill > joueur.getNbSkills())
			{
				std::cin >> select_skill;
			}
			sort=joueur.getSkill(select_skill);
			if (joueur.available(sort))
			{
				done=true;
			}
			else std::cerr << "Pas assez de mana" << std::endl;
		}
	}
	return sort;
}

Skill Game::selectSkillMonstre(Character monstre)
{
	bool done=false; //vérifie si la compétence a bien été choisie
	Skill sort;
	while (!done)
	{
		srand (time(NULL));
		int select;	//faire des sélections
		select=rand() %monstre.getNbSkills() + 1;	//retourne une valeur alléatoire entière entre 1 et le nbre de skills du mob
		sort=monstre.getSkill(select);
		if (monstre.available(sort))
		{
			done=true;
		}
	}
	return sort;
}

bool Game::tour(Skill sortJoueur, Character &monstre, Skill sortMonstre, bool &victoire)
{
		//retourne true si c'est la fin du combat false sinon
	int prioriteJoueur;
	int manaCostJoueur=sortJoueur.getManaCost();
	int damageJoueur=sortJoueur.getDamage();
	//std::cerr<<"mana cost:"<<manaCostJoueur<<", damage joueur:"<<damageJoueur<<std::endl;

	int manaCostMonstre=sortMonstre.getManaCost();
	int damageMonstre=sortMonstre.getDamage();
	int prioriteMonstre;
	//std::cerr<<"mana cost monstre:"<<manaCostMonstre<<", damage mob:"<<damageJoueur<<std::endl;

	prioriteJoueur=joueur.getSpeed() + sortJoueur.getPriority();
	prioriteMonstre=monstre.getSpeed() + sortMonstre.getPriority();
	if (prioriteJoueur>=prioriteMonstre)
	{
			//Le joueur joue en premier
				//Calcul du cout en mana
			joueur.editMana(manaCostJoueur);
				//Affiche les détails de l'action
			vue.afficheCombatDetails(joueur, sortJoueur);
			bool cible=sortJoueur.getTarget();
			if (cible==true)	//Si sible==true, on cible soit-meme
			{
				joueur.editLife(damageJoueur);	//si damage<0 -> soin
			}
			else				//cible->monstre
			{
				monstre.editLife(damageJoueur);
			}

			if (monstre.isAlive()==false && joueur.isAlive()==false)
			{
				//std::cerr << "la1" << std::endl;
				victoire=false;
				return true;
			}
			else if (monstre.isAlive()==false)
			{
				//std::cerr << "la2" << std::endl;
				//std::cerr<<"monstre vie:"<<monstre.getLife().first<<std::endl;
				victoire=true;
				return  true;
			}
			else if (joueur.isAlive()==false)
			{
				//std::cerr << "la3" << std::endl;
				victoire=false;
				return  true;
			}

			//Le monstre en second
			monstre.editMana(manaCostMonstre);
				//Affiche les détails de l'action
			vue.afficheCombatDetails(monstre, sortMonstre);
			cible=sortMonstre.getTarget();
			if (cible==true)
			{
				monstre.editLife(damageMonstre);
			}
			else
			{
				joueur.editLife(damageMonstre);
			}

			if (monstre.isAlive()==false && joueur.isAlive()==false)
			{
				victoire=false;
				return true;
			}
			else if (monstre.isAlive()==false)
			{
				victoire=true;
				return  true;
			}
			else if (joueur.isAlive()==false)
			{
				victoire=false;
				return  true;
			}
	}
	else
	{
			//Le monstre joue en premier
			monstre.editMana(manaCostMonstre);
				//Affiche les détails de l'action
			vue.afficheCombatDetails(monstre, sortMonstre);
			bool cible=sortMonstre.getTarget();
			if (cible==true)
			{
				monstre.editLife(damageMonstre);
			}
			else
			{
				joueur.editLife(damageMonstre);
			}

			if (monstre.isAlive()==false && joueur.isAlive()==false)
			{
				victoire=false;
				return true;
			}
			else if (monstre.isAlive()==false)
			{
				victoire=true;
				return  true;
			}
			else if (joueur.isAlive()==false)
			{
				victoire=false;
				return  true;
			}

			//Le joueur joue en second
			joueur.editMana(manaCostJoueur);	//Calcul du cout en mana
				//Affiche les détails de l'action
			vue.afficheCombatDetails(joueur, sortJoueur);
			cible=sortJoueur.getTarget();
			if (cible==true)	//Si sible==true, on cible soit-meme
			{
				joueur.editLife(damageJoueur);	//si damage<0 -> soin
			}
			else				//cible->monstre
			{
				monstre.editLife(damageJoueur);
			}

			if (monstre.isAlive()==false && joueur.isAlive()==false)
			{
				victoire=false;
				return true;
			}
			else if (monstre.isAlive()==false)
			{
				victoire=true;
				return  true;
			}
			else if (joueur.isAlive()==false)
			{
				victoire=false;
				return  true;
			}
	}
	//A la fin du tour, si les deux son encore en vie, le combat n'est pas fini
	return false;
}

	/******************
	 	Fin partie combat
	******************/

