#pragma once

//Field
#define FIELDSIZE			31

//Centipede
#define CENTIPEDE_SPEED		8.0f
#define CENTISEGMENT_WIDTH	.875f
#define CENTISEGMENT_HEIGHT 1.0f

//Player
#define MOVEMENT_SPEED		10.0f
#define PLAYER_WIDTH		0.83f
#define PLAYER_HEIGHT		0.95f
#define AREA				8.0f

//Mushrooms
#define DENSITY				7		// 0 - 100 %

//Bullets
#define COOLDOWN			.5f
#define BULLET_WIDTH		.125f
#define BULLET_HEIGHT		.5f
#define BULLET_SPEED		-20.0f

//Shader
#define VERTEX_SHADER		"vertex.shader"
#define FRAGMENT_SHADER		"fragment.shader"
#define SPRITE_SHEET		"centipedeSprites.jpg"

//Controls
#define MOVE_LEFT			GLFW_KEY_LEFT
#define MOVE_RIGHT			GLFW_KEY_RIGHT
#define MOVE_UP				GLFW_KEY_UP
#define MOVE_DOWN			GLFW_KEY_DOWN

#define SHOOT				GLFW_KEY_SPACE
#define CLOSE_GAME			GLFW_KEY_ESCAPE
