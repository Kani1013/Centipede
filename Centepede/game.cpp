#include "game.h"

//////////////////////////////////////////////
// All measurements are in FieldUnits.		//
// They get converted to pixels/absolutes	//
// in the shaders							//
//////////////////////////////////////////////

Game::Game()
{
	model = new Model();
	view = new View(model);
	controller = new Controller(model);
}

Game::~Game()
{
}

bool Game::isRunning() {
	return ( !shouldClose && (!view->isClosed()) && model->isRunning());
}

void Game::Update(GLfloat tpf)
{
	controller->pollEvents();
	model->update(tpf);
	view->rePaint();
}

void Game::Terminate()
{
	shouldClose = true;
}