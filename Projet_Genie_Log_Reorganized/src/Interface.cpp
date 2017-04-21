#include "Interface.h"
#include <iostream>

using namespace std;

void Interface::afficheCombat(Character perso, Character mob)
{
    afficheMob(Character mob);
    for(int i = 0; i<40 ;i++){cout << "-";} //ligne séparation
    cout<<"\n"<<endl;
    affichePerso(Character perso);
    cout<<"Que voulez-vous faire ?"<<endl;
}

void Interface::afficheCombatDetails(Character perso, int skillChoix)
{
    Skill skill = perso.getSkill(skillChoix);
    cout << perso.getName() << " utilise " << skill.getName() << ", il inflige " << skill.getDamage() << "de dégats." << endl;
}

void Interface::afficheSkill(Character perso)
{
    cout<<"     Action      Dégats      Cost"<<endl;
    for(int i = 1; i<perso.getNbSkill() ; i++)
    {
        Skill skill = perso.getSkill(i);
        cout<<i<< "- " << skill.getName() << skill.getDamage() << skill.getManaCost() <<"\n"<<endl;
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
    afficheSkill();
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
}

void Interface::afficheSelectP(Character perso)
{
    affichePerso(Character perso);
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

void Interface::afficheWinC(Map carte)
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
