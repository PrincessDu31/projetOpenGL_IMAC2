#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <iostream>
#include <glimac/Interface.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>
#include <glimac/Vector.hpp>

using namespace glimac;
using namespace std;


struct MapProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureMap;
    GLint uSizeMap;

    // GLint uTextureOtherTextureIfWeWant;

    MapProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/grid.vs.glsl",
                              applicationPath.dirPath() + "shaders/grid.fs.glsl")) {	//if mutlitexturing mutli3D.fs.glsl
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uSizeMap = glGetUniformLocation(m_Program.getGLId(), "uSizeMap");

        // uTextureMap = glGetUniformLocation(m_Program.getGLId(), "uTextureMap");
        // uTextureOtherTextureIfWeWant = glGetUniformLocation(m_Program.getGLId(), "uTextureCloud");
    }
};

struct CubeProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    // GLint uTextureOtherTextureIfWeWant;

    CubeProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/cube.vs.glsl",
                              applicationPath.dirPath() + "shaders/cube.fs.glsl")) {	//if mutlitexturing mutli3D.fs.glsl
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        // uTextureOtherTextureIfWeWant = glGetUniformLocation(m_Program.getGLId(), "uTextureCloud");
    }
};

struct AleatoirusProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    // GLint uTextureOtherTextureIfWeWant;

    AleatoirusProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/alea.vs.glsl",
                              applicationPath.dirPath() + "shaders/alea.fs.glsl")) {    //if mutlitexturing mutli3D.fs.glsl
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        // uTextureOtherTextureIfWeWant = glGetUniformLocation(m_Program.getGLId(), "uTextureCloud");
    }
};


int main(int argc, char** argv) {



    Interface interface;
    interface.createWorld();

	interface.getMap().testMapLoading();
   
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
    MapProgram mapProgram(applicationPath);
	CubeProgram cubeProgram(applicationPath);
    AleatoirusProgram aleatoirusProgram(applicationPath);



    glEnable(GL_DEPTH_TEST);

    glm::mat4 projMatrix, MVMatrix, NormalMatrix;
    projMatrix = glm::perspective(glm::radians(70.f), windowWidth/(float)windowHeight, 0.1f, 100.f);
    MVMatrix = glm::translate(MVMatrix, glm::vec3(0,0,-5));
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


	GLuint vbo;
 

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Sommets du quad
    Vertex3DColor vertices[] = {
        //face avant
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(0,0,1), glm::vec3(1, 0, 0)), // Sommet 0 - 0
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(0,0,1), glm::vec3(0, 1, 0)), // Sommet 1 - 1
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(0,0,1), glm::vec3(0, 0, 1)), // Sommet 2 - 2
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(0,0,1), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

    };

   	GLint nbTriangles = 2;
    glBufferData(GL_ARRAY_BUFFER, nbTriangles*3 * sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    uint32_t indices[] = {
        0, 1, 2, 0, 2, 3,
    };
    GLuint nbIndices = 6;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nbIndices * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)offsetof(Vertex3DColor,position));

    const GLuint VERTEX_ATTR_COLOR = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)offsetof(Vertex3DColor,color));
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    const GLuint VERTEX_ATTR_NORMAL = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)offsetof(Vertex3DColor,normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    glBindVertexArray(0);
    // Application loop:
	FreeflyCamera camera (glm::vec3(0, 0,  interface.getMap().getHeight()*0.5));
    glm::mat4 viewMatrix;
	glm::mat4 globalMVMatrix;

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


        globalMVMatrix = camera.getViewMatrix();

        //MAP DRAWING
        glBindVertexArray(1);   

        mapProgram.m_Program.use();
    
        float angle = M_PI * 0.5;

        glm::mat4 mapMVMatrix = glm::translate(globalMVMatrix, glm::vec3(0, -0.5, 0));
        mapMVMatrix = glm::rotate(mapMVMatrix, angle, glm::vec3(1, 0, 0));
        mapMVMatrix = glm::scale(mapMVMatrix, glm::vec3(interface.getMap().getWidth(), interface.getMap().getHeight(), 0));

        projMatrix = projMatrix;
        glUniformMatrix4fv(mapProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(mapMVMatrix));
        glUniformMatrix4fv(mapProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(mapMVMatrix))));
        glUniformMatrix4fv(mapProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * mapMVMatrix));    

        glm::vec2 sizeMap = glm::vec2(interface.getMap().getWidth(), interface.getMap().getHeight());
        glUniform2f(mapProgram.uSizeMap, sizeMap.x, sizeMap.y);
      	
        glDrawElements(GL_TRIANGLES, 2*3, GL_UNSIGNED_INT, 0);
      

		glBindVertexArray(0);

		globalMVMatrix = camera.getViewMatrix();

        //WALL DRAWING
		cubeProgram.m_Program.use();

		glBindVertexArray(1);   

		glm::mat4 cubeMVMatrix = glm::scale(globalMVMatrix, glm::vec3(1, 1, 1));

        projMatrix = projMatrix;
        glUniformMatrix4fv(cubeProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(cubeMVMatrix));
        glUniformMatrix4fv(cubeProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cubeMVMatrix))));
        glUniformMatrix4fv(cubeProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * cubeMVMatrix));    

      	glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        //ALEATOIRUS DRAWING

        glBindVertexArray(1);
        aleatoirusProgram.m_Program.use();

        glm::mat4 aleaMVMatrix = glm::translate(globalMVMatrix, glm::vec3(0.5, 0, 0));
       

        projMatrix = projMatrix;
        glUniformMatrix4fv(aleatoirusProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(aleaMVMatrix));
        glUniformMatrix4fv(aleatoirusProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(aleaMVMatrix))));
        glUniformMatrix4fv(aleatoirusProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * aleaMVMatrix));    

        glDrawElements(GL_TRIANGLES, 2*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);


		if (movingFront == true) {
			// if (abs(camera.getPosition().x) < interface.getMap().getWidth() * 0.5 )
			 	camera.moveFront(0.05);
			// else
			// 	camera.moveFront(-0.2);
			// cout << "cam : " << abs(camera.getPosition().x) << endl;
			// cout << "width : " << interface.getMap().getWidth() * 0.5 << endl;

		}
		if (movingBack == true) camera.moveFront(-0.5);
		if (turningLeft == true) camera.rotateLeft(5);
		if (turningRight == true) camera.rotateLeft(-5);



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
     
        
       	
        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
