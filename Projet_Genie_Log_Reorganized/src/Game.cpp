#include "../include/Game.h"
using namespace std;

	/************************
	Constructeurs, get et set
	************************/

//test

Game::Game()
{
	vue.afficheTHEGAME();
	try
	{
		carte=Map();
		nbRestant=carte.mobRestants();
		setPileMob();
		partie();
	}
	catch (const string & err)
	{
		throw err;
	}
}

Game::Game(Character joueur)
{
	this->joueur=joueur;
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
	fstream mobFile;
	mobFile.open("./config/monstres.db", fstream::in);
	if (mobFile.is_open())
	{
		Character mobTmp;
		string characterString;
		for (int i=0; i<nbRestant; i++)
		{
			if (!mobFile.eof())
			{
				getline(mobFile, characterString);
				try
				{
					mobTmp=Character(characterString);
				}
				catch(const string & err)
				{
					throw err;
				}
				pileMob.push(mobTmp);
			}
			else throw string("erreur pas assé de monstres");
		}
		mobFile.close();
	}
	else
	{
		throw string("Lecture du fichier monstres impossible");
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
		try
		{
			int nbPersos=0;
			if(!selection_perso(nbPersos)) return;
		}
		catch (const string & err)
		{
			throw err;
		}
		vue.afficheDebutJeu();
			//Variable pour choisir une direction ou aller sur la carte
		string direction;
		while (finPartie==false)
		{
			//vue.afficheMap();
				//On se déplace tant qu'on ne rencontre pas de monstre
			while (carte.verif_monstre()!=true)
			{
				vue.afficheMap(carte, joueur);
				cin >> direction;
				if (direction=="quitter") {
					cout<<"Merci d'avoir joué!"<<endl;
					return;
				}
				while(!carte.deplacer(direction[0]))
				{
					cerr << "Choisissez une direction" << endl;
					cin >> direction;
					if (direction=="quitter") {
						cout<<"Merci d'avoir joué!"<<endl;
						return;
					}
				}
					//Heal si case soin
				if (carte.verif_Soin())
				{
					pair <int, int> vieJoueur=joueur.getLife();
					if (vieJoueur.first <= vieJoueur.second/2)
					{
						int soin=vieJoueur.second/2;
						joueur.editLife(0-soin);
						carte.unsetmob();
					}
				}
			}
			Character monstre=pileMob.top();
			pileMob.pop();
			carte.unsetmob();
			bool quitter=false;
			victoire=combat(monstre, quitter);
			if (quitter==true)
			{
				return;
			}
			else if (victoire)
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
				return;
				//Afficher you died
			}
		}
		vue.afficheWinF();
		//Afficher victoire totale!!!
	}

bool Game::selection_perso(int &nbPersos) {
	ifstream liste_persos("./config/liste_persos.db");
	if(liste_persos){
		string perso;
		string choix;
		getline(liste_persos, perso);

		if (nbPersos==0)
		{
			while(!liste_persos.eof())
			{
				nbPersos++;
				getline(liste_persos, perso);
			}
			return selection_perso(nbPersos);
		}

		int i=1;

		while (!liste_persos.eof()){
			try
			{
				joueur = Character(perso);
			}
			catch(const string & err)
			{
				throw err;
			}
				//affichage_selection_perso;
			vue.afficheSelectP(joueur, nbPersos, i);
			cin >> choix;
			if (choix=="quitter") {
				cout<<"Merci d'avoir joué!"<<endl;
				return false;
			}
			else {
				while (choix!="o" && choix!="n" && choix!="O" && choix!="N") {
					cout << "erreur entrez o ou n" << endl;
					cin >> choix;
					if (choix=="quitter") {
						cout<<"Merci d'avoir joué!"<<endl;
						return false;
					}
				}
 				if (choix=="o" || choix=="O") return true;
				getline(liste_persos, perso);
			}
			i++;
		}
		liste_persos.close();
		return selection_perso(nbPersos);
	}
	throw  string("Impossible d'ouvrir le fichier liste_persos");
	return false;
}

	/********************
		   combat
	********************/
bool Game::combat(Character monstre, bool &quitter)
{
	bool victoire = false;		//dit si on as gagnés
	bool finCombat=false;		//dit si c'est la fin du combat
		//bool pour savoir si le joueur veux quitter
	quitter=false;
	vue.afficheCombatDebut(joueur, monstre);
	while (finCombat!=true)
	{
			//au départ, on affiche les infos du mob et du joueur + compétences du joueur
		//vue.afficheMob(monstre);
		//vue.affichePerso(joueur);
		vue.afficheCombat(joueur, monstre);
		Skill sortJoueur, sortMonstre;
		sortJoueur=selectSkillJoueur(quitter);
		if (quitter==true) return victoire;
		sortMonstre=selectSkillMonstre(monstre);
		finCombat=tour(sortJoueur, monstre, sortMonstre, victoire);
	}
	return victoire;
}

Skill Game::selectSkillJoueur(bool &quitter)
{
	bool done=false; //vérifie si la compétence a bien été choisie
	Skill sort;
	while (done!=true)
	{
		string select;	//faire des sélections
		cin >> select;
		if (select=="quitter") {
			cout<<"Merci d'avoir joué!"<<endl;
			done=true;
			quitter=true;
			sort=Skill();
		}
		else if (!isdigit(select[0])) cout<<"Erreur ce sort n'existe pas:";
		else {
			int select_skill=stoi(select);
			if ( select_skill<=0 || select_skill > joueur.getNbSkills()) cout<<"Erreur ce sort n'existe pas:";
			else {
				sort=joueur.getSkill(select_skill);
				if (joueur.available(sort))
				{
					done=true;
				}
				else cerr << "Pas assez de mana.Choisissez un autre sort:";
			}
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

	int manaCostMonstre=sortMonstre.getManaCost();
	int damageMonstre=sortMonstre.getDamage();
	int prioriteMonstre;

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
	joueur.editMana(-1);
	monstre.editMana(-1);
	//A la fin du tour, si les deux son encore en vie, le combat n'est pas fini
	return false;
}

	/******************
	 	Fin partie combat
	******************/

