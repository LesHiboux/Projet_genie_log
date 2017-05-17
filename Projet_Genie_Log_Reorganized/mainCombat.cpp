#include "./include/Game.h"

using namespace std;

int main()
{
	try
	{
		string strChar="{Bryan;15/20;8/10;3;Sword Slash/3/0/1/0;Dash Dagger/5/3/2/0;Demacia/10/8/0/0;70}";
		Character joueur(strChar);
		Game play(joueur);

		strChar="{Gobelin;15/15;8/8;3;Coup de poing/1/0/2/0;Coup de massue/3/1/1/0;Coup de dague/2/1/3/0;60}";
		Character monstre(strChar);

		bool quitter=false;
		bool winCombat=play.combat(monstre, quitter);

		if (quitter)
		{
			cerr<<"Quitter"<<endl;
		}
		else if(winCombat)
		{
			cerr<<"Victoire combat"<<endl;
		}
		else if(!winCombat)
		{
			cerr<<"Défaite combat"<<endl;
		}
	}
	catch (const std::string & err)
	{
		std::cerr<<err<<std::endl;
	}
}
