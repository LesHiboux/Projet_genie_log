#include "./include/Game.h"

int main()
{
	try
	{
		Game play = Game();
		play.partie();
	}
	catch (const string & err)
	{
		std::cerr<<err<<std::endl;
	}
}
