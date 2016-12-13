#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <iostream>
#include <glimac/Interface.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>


using namespace glimac;
using namespace std;


struct Vertex2DColor {
    glm::vec2 position;
    glm::vec3 color;
    Vertex2DColor(){}
    Vertex2DColor (glm::vec2 p, glm::vec3 c){
        position = p;
        color = c;
    }
};



   Interface interface;
   interface.createWorld();

	interface.getMap().testMapLoading();

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    SDLWindowManager windowManager(windowWidth, windowHeight, "GLImace");

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
     FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/grid.vs.glsl",
                                    applicationPath.dirPath() + "shaders/grid.fs.glsl");
    program.use();

        GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Sommets du quad
    Vertex2DColor vertices[] = {
        Vertex2DColor(glm::vec2(-1, -1), glm::vec3(1, 0, 0)), // Sommet 0
        Vertex2DColor(glm::vec2(1, -1), glm::vec3(0, 1, 0)), // Sommet 1
        Vertex2DColor(glm::vec2(1, 1), glm::vec3(0, 0, 1)), // Sommet 2
        Vertex2DColor(glm::vec2(-1, 1), glm::vec3(1, 1, 1)) // Sommet 3
    };
   	GLint nbTriangles = 2;
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    uint32_t indices[] = {
        0, 1, 2, 0, 2, 3
    };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_COLOR = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, position));
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, color));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // Application loop:
	FreeflyCamera camera;
    glm::mat4 viewMatrix;

	bool movingFront = false;
	bool movingBack = false;
	bool turningLeft = false;
	bool turningRight = false;

	bool done = false;
	while(!done) {


   		/*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(1);   
      	glDrawElements(GL_TRIANGLES, 2*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glBindVertexArray(0);


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
                  

     
        
       	
        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
