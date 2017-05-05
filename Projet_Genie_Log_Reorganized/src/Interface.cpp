#include "../include/Interface.h"
#include <iostream>

using namespace std;

void Interface::afficheTHEGAME()
{
        system("clear");  
	cout<<endl<<endl<<endl;                                            
	cout<<"			_/_/_/_/_/  _/    _/  _/_/_/_/        _/_/_/    _/_/    _/      _/  _/_/_/_/"<<endl;
	cout<<"			   _/      _/    _/  _/            _/        _/    _/  _/_/  _/_/  _/"<<endl;         
	cout<<"			  _/      _/_/_/_/  _/_/_/        _/  _/_/  _/_/_/_/  _/  _/  _/  _/_/_/"<<endl;      
	cout<<"			 _/      _/    _/  _/            _/    _/  _/    _/  _/      _/  _/"<<endl;           
	cout<<"			_/      _/    _/  _/_/_/_/        _/_/_/  _/    _/  _/      _/  _/_/_/_/"<<endl;
	cout<<endl;
	system("sleep 3");
}

void Interface::afficheDebutJeu()
{
    system("clear");
    cout<<"         Bienvenue dans notre jeu valeureux combattant \n             C'est ici que ta légende commence, \n           Va et renvoie dans les profondeurs de l'enfer ces monstres !! "<<endl;
    system("sleep 4");
}

void Interface::afficheCombatDebut(Character perso, Character mob)
{
    system("clear");
    cout<<"Vous rencontrez un monstre : \n "<<endl;
    afficheMob(mob);
    cout<<"Que le combat commence !!"<<endl;
    system("sleep 3");
}

void Interface::afficheCombat(Character perso, Character mob)
{
    system("clear");
    afficheMob(mob);
    for(int i = 0; i<40 ;i++){cout << "-";} //ligne séparation
    cout<<"\n"<<endl;
    affichePerso(perso);
    cout<<"Que voulez-vous faire ?"<<endl;
}

void Interface::afficheCombatDetails(Character perso, Skill skill)
{
    cout << perso.getName() << " utilise " << skill.getName() << ", il inflige " << skill.getDamage() << " de dégats." << endl;
    system("sleep 1");
    cout<<endl;
}

void Interface::afficheSkill(Character perso)
{
    cout<<"     Action      Dégats      Cost"<<endl;
    for(int i = 1; i<=perso.getNbSkills() ; i++)
    {
        Skill skill = perso.getSkill(i);
        cout<<i<< "- " << skill.getName() << "     " << skill.getDamage() << "          " << skill.getManaCost() <<"\n"<<endl;
    }
}

void Interface::affichePerso(Character perso)
{
    cout<<perso.getName()<<"\n"<<endl;
    cout << "PV : (" << perso.getLife().first << "/" << perso.getLife().second << ")  [";
    for (int i = 0; i < perso.getMaxLife(); i++)
    {
        if(i < perso.getLife().first)
        {
            cout << "#";
        }
        else
        {
            cout << "-";
        }
    }
    cout<< "] \n" << endl;

    cout << "PM : (" << perso.getMana().first << "/" << perso.getMana().second << ")  [";
    for (int i = 0; i < perso.getMaxMana(); i++)
    {
        if(i < perso.getMana().first)
        {
            cout << "0";
        }
        else
        {
            cout << "-";
        }
    }
    cout << "] \n" << endl;
    for(int i = 0; i<40 ;i++){cout << "-";} //ligne séparation
    cout<<"\n"<<endl;

    afficheSkill(perso);

    cout<<"\n"<<endl;
}

void Interface::afficheMob(Character mob)
{
    cout<<mob.getName()<<"\n"<<endl;
    cout << "PV : (" << mob.getLife().first << "/" << mob.getLife().second << ") [";
    for (int i = 0; i < mob.getMaxLife(); i++)
    {
        if(i < mob.getLife().first)
        {
            cout << "#";
        }
        else
        {
            cout << "-";
        }
    }
    cout<<"]\n"<<endl;
}

void Interface::afficheSelectP(Character perso)
{
    system("clear");
    affichePerso(perso);
    cout<<"Voulez-vous jouer avec ce personnage ? [O/N] "<<endl;
}

void Interface::afficheLoose()
{
    system("clear");
    cout<<"\\    /  ____               ____    __    ____   _____     ____    ____    _____    | "<<endl;
    cout<<" \\  /  /    \\  |    |     /    \\  |  \\  |       |    \\   |       /    \\   |    \\   | "<<endl;
    cout<<"  \\/   |    |  |    |     |____|  |__/  |__     |    |   |__     |____|   |    |   | "<<endl;
    cout<<"  ||   |    |  |    |     |    |  |  \\  |       |    |   |       |    |   |    |     "<<endl;
    cout<<"  ||   \\____/  \\____/     |    |  |  |  |____   |____/   |____   |    |   |____/   0 "<<endl;
}

void Interface::afficheWinC(Map carte)
{
    cout<<"\n"<<endl;
    cout<<"BRAVO !!!! Vous avez gagné ce combats :)"<<endl;
    cout<<"Il vous reste "<<carte.mobRestants()<<" monstres a battre."<<endl;
    cout<<"Continuez sur votre lancee victorieux aventurier !"<<endl;
    system("sleep 2");
}

void Interface::afficheWinF()
{
    system("clear");
    cout<<"\\    /  ____                           0   |\\    |   |"<<endl;
    cout<<" \\  /  /    \\  |    |   \\          /       | \\   |   |"<<endl;
    cout<<"  \\/   |    |  |    |    \\        /    |   |  \\  |   |"<<endl;
    cout<<"  ||   |    |  |    |     \\  /\\  /     |   |   \\ |    "<<endl;
    cout<<"  ||   \\____/  \\____/      \\/  \\/      |   |    \\|   0"<<endl;
}

void Interface::afficheMap(Map carte, Character perso)
{
    system("clear");
    cout<<perso.getName()<<"\n"<<endl;
    cout << "PV : (" << perso.getLife().first << "/" << perso.getLife().second << ")  [";
    for (int i = 0; i < perso.getMaxLife(); i++)
    {
        if(i < perso.getLife().first)
        {
            cout << "#";
        }
        else
        {
            cout << "-";
        }
    }
    cout<< "] \n" << endl;
    cout<<"Monstres restant : "<<carte.mobRestants()<<endl;
    int ** map = carte.getMapApparence();
    for(int i = 0; i<carte.getTaille().first; i++)
    {
        for( int j = 0; j<carte.getTaille().second; j++)
        {
            if(i == carte.getPosition().first && j == carte.getPosition().second){cout<<"o";}
            else
            {
                switch(map[i][j])
                {
                    case 0: cout<<"."; // ?
                            break;
                    case 1: cout<<"A"; //montagne
                            break;
                    case 3: cout<<"#"; //chemin safe
                            break;
                    case 9: cout<<"~"; //zone d'eau
                            break;
                    case 5: cout<<"H"; //pont
                            break;
                    case 2: cout<<"T"; // ?
                            break;
                    default:
                            cout<<".";
                            break;
                }
            }
        }
        cout<<endl;
    }
    cout<<"Choisissez une direction [z/q/s/d]: "<<endl;
}
