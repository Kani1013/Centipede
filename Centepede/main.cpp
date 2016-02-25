#include "game.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
	Game* game = new Game();

	GLfloat tpf = 0;
	GLfloat currentTime = (GLfloat) glfwGetTime();
	GLfloat timePassed = currentTime;

	while (game->isRunning())
	{
		//Update tpf (time per frame)
		currentTime = (GLfloat) glfwGetTime();
		tpf = currentTime - timePassed;
		timePassed = currentTime;
		//system("cls");
		//std::cout << 1 / tpf << "\n";


		game->Update(tpf);
	}

	return 0;
}