#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <iostream>
#include <glimac/Interface.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>


using namespace glimac;
using namespace std;


struct Vertex3DColor {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
    Vertex3DColor(){}
    Vertex3DColor (glm::vec3 p, glm::vec3 n, glm::vec3 c){
        position = p;
        normal = n;
        color = c;
    }
};


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
    Program program = loadProgram(applicationPath.dirPath() + "shaders/test.vs.glsl",
                                    applicationPath.dirPath() + "shaders/test.fs.glsl");
    program.use();

        GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // GLint uMVPMatrix;
    // GLint uMVMatrix;
    // GLint uNormalMatrix;

    //  glm::mat4 projMatrix, MVMatrix, NormalMatrix;
    // projMatrix = glm::perspective(glm::radians(70.f), windowWidth/(float)windowHeight, 0.1f, 100.f);
    // MVMatrix = glm::translate(MVMatrix, glm::vec3(0,0,-5));
    // NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    //Sommets du quad
    Vertex3DColor vertices[] = {
        //face avant
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(0,0,1), glm::vec3(1, 0, 0)), // Sommet 0 - 0
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(0,0,1), glm::vec3(0, 1, 0)), // Sommet 1 - 1
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(0,0,1), glm::vec3(0, 0, 1)), // Sommet 2 - 2
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(0,0,1), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

        //face arrière
        Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0,0,-1), glm::vec3(1, 0, 0)), // Sommet 4 - 4
        Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), glm::vec3(0,0,-1), glm::vec3(0, 1, 0)), // Sommet 5 - 5
        Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), glm::vec3(0,0,-1), glm::vec3(0, 0, 1)), // Sommet 6 - 6
        Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), glm::vec3(0,0,-1), glm::vec3(1, 1, 1)), // Sommet 7 - 7

        //face haut
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(0,1,0), glm::vec3(0, 0, 1)), // Sommet 2 - 8
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(0,1,0), glm::vec3(1, 1, 1)), // Sommet 3 - 9
        Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), glm::vec3(0,1,0), glm::vec3(0, 0, 1)), // Sommet 6 - 10
        Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), glm::vec3(0,1,0), glm::vec3(1, 1, 1)), // Sommet 7 - 11

        //face bas
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(0,-1, 0), glm::vec3(1, 0, 0)), // Sommet 0 - 12
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(0,-1, 0), glm::vec3(0, 1, 0)), // Sommet 1 - 13
        Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0,-1, 0), glm::vec3(1, 0, 0)), // Sommet 4 - 14
        Vertex3DColor(glm::vec3(0.5, -0.5, -0.5), glm::vec3(0,-1, 0), glm::vec3(0, 1, 0)), // Sommet 5 - 15

        //face gauche
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.5), glm::vec3(-1,0,0), glm::vec3(1, 0, 0)), // Sommet 0 - 16 
        Vertex3DColor(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(-1,0,0), glm::vec3(1, 0, 0)), // Sommet 4 -17
        Vertex3DColor(glm::vec3(-0.5, 0.5, -0.5), glm::vec3(-1,0,0), glm::vec3(1, 1, 1)), // Sommet 7 - 18 
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(-1,0,0), glm::vec3(1, 1, 1)), // Sommet 3 - 19

        //face droite
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.5), glm::vec3(1,0,0), glm::vec3(0, 1, 0)), // Sommet 1 - 20
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.5), glm::vec3(1,0,0), glm::vec3(0, 0, 1)), // Sommet 2 - 21
        Vertex3DColor(glm::vec3(0.5, -0.5, -0.5),glm::vec3(1,0,0), glm::vec3(0, 1, 0)), // Sommet 5 - 22
        Vertex3DColor(glm::vec3(0.5, 0.5, -0.5), glm::vec3(1,0,0), glm::vec3(0, 0, 1)) // Sommet 6 - 23

    };

   	GLint nbTriangles = 12;
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    uint32_t indices[] = {
        0, 1, 2, 0, 2, 3,
        5, 6, 7, 5, 7, 4, 
        9, 8, 10, 9, 10, 11, 
        12, 13, 15, 12, 13, 14, 
        16, 17, 18, 16, 18, 19,
        20, 22, 23, 20, 23, 21
    };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex,position));

    const GLuint VERTEX_ATTR_NORMAL = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    const GLuint VERTEX_ATTR_TEX = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_TEX);
    glVertexAttribPointer(VERTEX_ATTR_TEX, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // Application loop:
    bool done = false;
    
 
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(1);   

        // MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0, 1, 0));
        // MVMatrix = glm::translate(MVMatrix, glm::vec3(0, 0, -5));
        // glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));

      	glDrawElements(GL_TRIANGLES, 36*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glBindVertexArray(0);
        
       	
        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
