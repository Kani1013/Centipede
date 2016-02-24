#pragma once

#include "gameObject.h"
#include "renderer.h"

void GameObject::reDraw(Renderer* renderer)
{
	if (isVisible) renderer->draw(this);
}