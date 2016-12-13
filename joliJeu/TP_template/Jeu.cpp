#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Interface.hpp>
#include <glimac/FreeflyCamera.hpp>


using namespace glimac;
using namespace std;




int main(int argc, char** argv) {

   Interface interface;
   interface.createWorld();

	interface.getMap().testMapLoading();

	// Initialize SDL and open a window
	SDLWindowManager windowManager(800, 600, "GLImac");

	// Initialize glew for OpenGL3+ support
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError) {
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    // Application loop:
	FreeflyCamera camera;
    glm::mat4 viewMatrix;

	bool movingFront = false;
	bool movingBack = false;
	bool turningLeft = false;
	bool turningRight = false;

	bool done = false;
	while(!done) {




		if (movingFront == true) camera.moveFront(0.5);
		if (movingBack == true) camera.moveFront(-0.5);
		if (turningLeft == true) camera.rotateLeft(0.5);
		if (turningRight == true) camera.rotateLeft(-0.5);


	 	SDL_Event e;
     	while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            switch(e.type) {

            case SDL_KEYDOWN:

				if(e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_UP) {
					movingFront = true;
				}
				else if(e.key.keysym.sym == SDLK_RIGHT) {
					turningRight = true;
                }
				else if(e.key.keysym.sym == SDLK_LEFT) {
					turningLeft = true;
				}
				else if(e.key.keysym.sym == SDLK_DOWN) {
					movingBack = true;
				}
				break;

			
			case SDL_KEYUP:

				if(e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_UP) {
					movingFront = false;
				}
				else if(e.key.keysym.sym == SDLK_RIGHT) {
					turningRight = false;
                }
				else if(e.key.keysym.sym == SDLK_LEFT) {
					turningLeft = false;
				}
				else if(e.key.keysym.sym == SDLK_DOWN) {
					movingBack = false;
				}
                break;

            }
                  
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
