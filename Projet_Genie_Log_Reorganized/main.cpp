#include "./include/Game.h"

int main()
{
	try
	{
		Game play = Game();
		play.partie();
	}
	catch (string const& err)
	{
		std::cerr<<err<<std::endl;
	}
}
