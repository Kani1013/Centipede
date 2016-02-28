#pragma once

//Field
#define FIELDSIZE				31

//Centipede
#define CENTIPEDE_SPEED			12.0f
#define CENTIPEDE_LENGTH		6
#define CENTISEGMENT_WIDTH		.875f
#define CENTISEGMENT_HEIGHT		1.0f
#define CENTI_SPAWN_INTERVAL_S	20
#define SEGMENT_SPACING			0.125f

//Player
#define MOVEMENT_SPEED			10.0f
#define PLAYER_WIDTH			0.83f
#define PLAYER_HEIGHT			0.95f
#define AREA					8.0f

//Mushrooms
#define DENSITY					7

//Bullets
#define COOLDOWN				.5f
#define BULLET_WIDTH			.125f
#define BULLET_HEIGHT			.5f
#define BULLET_SPEED			-30.0f

//Shader
#define VERTEX_SHADER			"vertex.shader"
#define FRAGMENT_SHADER			"fragment.shader"

//Controls
#define MOVE_LEFT				GLFW_KEY_LEFT
#define MOVE_RIGHT				GLFW_KEY_RIGHT
#define MOVE_UP					GLFW_KEY_UP
#define MOVE_DOWN				GLFW_KEY_DOWN
#define SHOOT					GLFW_KEY_SPACE
#define CLOSE_GAME				GLFW_KEY_ESCAPE
#define NEW_GAME				GLFW_KEY_F1

//Window
#define SCREEN_WIDTH			800
#define SCREEN_HEIGHT			800
#define FULLSCREEN				1