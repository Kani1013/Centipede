#include "view.h"

View::View(Model* model)
{
	View::model = model;

	//Create window
	display = new Display(SCREEN_WIDTH, SCREEN_HEIGHT, "Centipede | Projektarbeit von Nikolaj Kappler");
	//glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//Field size in pixels is width or height of display, whatever is smaller of both
	GLuint fieldSizeInPX = SCREEN_HEIGHT;
	if ((GLuint) SCREEN_WIDTH < fieldSizeInPX) fieldSizeInPX = (GLuint) SCREEN_WIDTH;

	//Load SpriteSheet
	loadSpriteSheet();

	//Load Shader
	shader = new Shader(VERTEX_SHADER, FRAGMENT_SHADER, display);
	shader->setResolutions(SCREEN_WIDTH, SCREEN_HEIGHT, TextureWidth, TextureHeight, fieldSizeInPX);
	shader->Use();

	//Create Renderer
	renderer = new Renderer();
}


View::~View()
{
}


void View::rePaint() {
	display->Update();
	model->reDraw(renderer);
}

bool View::isClosed()
{
	return display->isClosed();
}

void View::loadSpriteSheet()
{
	std::cout << "Load SpriteSheet\n";
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// Load image, create texture and generate mipmaps
	unsigned char* image = SOIL_load_image(SPRITE_SHEET, &TextureWidth, &TextureHeight, 0, SOIL_LOAD_RGBA);
	if (image == 0) {
		std::cout << "Failed to load SpriteSheet " << SPRITE_SHEET << "\n";
		glfwTerminate();
		system("pause");
		display->Close();
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TextureWidth, TextureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
}