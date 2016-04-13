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


		game->Update(tpf);
	}

	return 0;
}