#include "Interface.h"
#include <iostream>

using namespace std;

void Interface::afficheCombat()
{
    afficheMob();
    for(int i = 0; i<40 ;i++){cout << "-";} //ligne séparation
    cout<<"\n"<<endl;
    affichePerso();
    cout<<"Que voulez-vous faire ?"<<endl;
}

void Interface::afficheCombatDetails()
{
    cout<<"name A (perso/mob selon priorite)"<<" utilise "<<"skill choisi"<<", il inflige "<<"nb degats skill."<<endl;
    cout<<"name B (perso/mob selon priorite)"<<" utilise "<<"skill choisi"<<", il inflige "<<"nb degats skill."<<endl;
}

void Interface::afficheSkill()
{
    cout<<"     Action      Dégats      Cost"<<endl;
    cout<<" 1- "<<"getSkill1 "<<" getDégats1 "<<" getCost1 "<<"\n"<<endl;
    cout<<" 2- "<<"getSkill1 "<<" getDégats2 "<<" getCost2 "<<"\n"<<endl;
    cout<<" 3- "<<"getSkill1 "<<" getDégats3 "<<" getCost3 "<<"\n"<<endl;
    cout<<" 4- "<<"getSkill1 "<<" getDégats4 "<<" getCost4 "<<"\n"<<endl;
}

void Interface::affichePerso()
{
    cout<<"Name perso \n"<<endl;
    cout << "PV : (" << "PV" << "/" << "PV_max" << ") [" << "######--" << "] \n" << endl;
    cout << "PM : (" << "PM" << "/" << "PM_max" << ") [" << "0000000-" << "] \n" << endl;
    for(int i = 0; i<40 ;i++){cout << "-";} //ligne séparation
    cout<<"\n"<<endl;
    afficheSkill();
    cout<<"\n"<<endl;
}

void Interface::afficheMob()
{
    cout<<"Name mob \n"<<endl;
    cout << "PV : (" << "PV" << "/" << "PV_max" << ") [" << "########" << "] \n" << endl;
}

void Interface::afficheSelectP()
{
    affichePerso();
    cout<<"Voulez-vous jouer avec ce personnage ? [O/N] "<<endl;
}

void Interface::afficheLoose()
{
    cout<<"\\    /  ____               ____    __    ____   ____    ____    ____    ____   | "<<endl;
    cout<<" \\  /  /    \\  |    |     /    \\  |  \\  |       |    \\   |       /    \\   | "<<endl;
    cout<<"  \\/   |    |  |    |     |____|  |__/  |__     |    |   |__     |____|   |    |   | "<<endl;
    cout<<"  ||   |    |  |    |     |    |  |  \\  |       |    |   |       |    |   |    |     "<<endl;
    cout<<"  ||   \\____/  \\____/     |    |  |  |  |____   |____/   |____   |    |   |____/   0 "<<endl;
}

void Interface::afficheWinC()
{
    cout<<"BRAVO !!!! Vous avez gagné ce combats :)"<<endl;
    cout<<"Il vous reste "<<carte.mobRestants()<<" a battre."<<endl;
    cout<<"Continuez sur votre lancee victorieux aventurier !"<<endl;
}

void Interface::afficheWinF()
{
    cout<<"\\    /  ____                           0   |\\    |   |"<<endl;
    cout<<" \\  /  /    \\  |    |   \\          /       | \\   |   |"<<endl;
    cout<<"  \\/   |    |  |    |    \\        /    |   |  \\  |   |"<<endl;
    cout<<"  ||   |    |  |    |     \\  /\\  /     |   |   \\ |    "<<endl;
    cout<<"  ||   \\____/  \\____/      \\/  \\/      |   |    \\|   0"<<endl;
}

void Interface::afficheMap(Map carte)
{
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
