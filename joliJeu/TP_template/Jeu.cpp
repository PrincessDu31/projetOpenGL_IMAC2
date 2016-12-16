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

#define TURNING_VAL 15

using namespace glimac;
using namespace std;



struct MapProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureMap;
    GLint uSizeMap;
    GLuint uniformMapFind;

   // GLint uniformMapFind;
    // GLint uTextureOtherTextureIfWeWant;

    MapProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/grid.vs.glsl",
                              applicationPath.dirPath() + "shaders/grid.fs.glsl")) {    //if mutlitexturing mutli3D.fs.glsl
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uSizeMap = glGetUniformLocation(m_Program.getGLId(), "uSizeMap");
   
     //   uFind = glGetUniformLocation(m_Program.getGLId(), "uFind");
        uniformMapFind = glGetUniformLocation(m_Program.getGLId(), "uniformMapFind");


	//uniformFind = glGetUniformBlockIndex​ (m_Program.getGLId(),"uniformFind[900]");
	//uniformFind = glGetUniformBlockIndex​ (m_Program.getGLId(),"uniformFind[900]");

        // uTextureMap = glGetUniformLocation(m_Program.getGLId(), "uTextureMap");
        // uTextureOtherTextureIfWeWant = glGetUniformLocation(m_Program.getGLId(), "uTextureCloud");
    }
};


struct WallProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureMap;

   // GLint uniformMapFind;
    // GLint uTextureOtherTextureIfWeWant;

    WallProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/wall.vs.glsl",
                              applicationPath.dirPath() + "shaders/wall.fs.glsl")) {    //if mutlitexturing mutli3D.fs.glsl
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
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
                              applicationPath.dirPath() + "shaders/cube.fs.glsl")) {    //if mutlitexturing mutli3D.fs.glsl
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

struct MonsterProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    // GLint uTextureOtherTextureIfWeWant;

    MonsterProgram(const FilePath& applicationPath):
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
    WallProgram wallProgram(applicationPath);
	CubeProgram cubeProgram(applicationPath);
    AleatoirusProgram aleatoirusProgram(applicationPath);
    MonsterProgram monsterProgram(applicationPath);



    glEnable(GL_DEPTH_TEST);

    glm::mat4 projMatrix, MVMatrix, NormalMatrix;
    projMatrix = glm::perspective(glm::radians(70.f), windowWidth/(float)windowHeight, 0.1f, 100.f);
    MVMatrix = glm::translate(MVMatrix, glm::vec3(0,0,-5));
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    //////////// PLAN /////////////////////
	GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //Sommets du quad
    Vertex3DColor vertices[] = {
        //face avant
		Vertex3DColor(glm::vec3(-0.5,-0.5, 0.5), glm::vec3(0,0,1), glm::vec3(1, 0, 0)), // Sommet 0 - 0		// FACE AVANT
		Vertex3DColor(glm::vec3( 0.5,-0.5, 0.5), glm::vec3(0,0,1), glm::vec3(0, 1, 0)), // Sommet 1 - 1
		Vertex3DColor(glm::vec3( 0.5, 0.5, 0.5), glm::vec3(0,0,1), glm::vec3(0, 0, 1)), // Sommet 2 - 2
		Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(0,0,1), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

		Vertex3DColor(glm::vec3(-0.5,-0.5, 0.5), glm::vec3(-1,0,0), glm::vec3(1, 0, 0)), // Sommet 0 - 0		// LEFT
		Vertex3DColor(glm::vec3(-0.5,-0.5,-0.5), glm::vec3(-1,0,0), glm::vec3(0, 1, 0)), // Sommet 1 - 1
		Vertex3DColor(glm::vec3(-0.5, 0.5,-0.5), glm::vec3(-1,0,0), glm::vec3(0, 0, 1)), // Sommet 2 - 2
		Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(-1,0,0), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

		Vertex3DColor(glm::vec3(-0.5,-0.5,-0.5), glm::vec3(0,0,-1), glm::vec3(1, 0, 0)), // Sommet 0 - 0		// BACK
		Vertex3DColor(glm::vec3( 0.5,-0.5,-0.5), glm::vec3(0,0,-1), glm::vec3(0, 1, 0)), // Sommet 1 - 1
		Vertex3DColor(glm::vec3( 0.5, 0.5,-0.5), glm::vec3(0,0,-1), glm::vec3(0, 0, 1)), // Sommet 2 - 2
		Vertex3DColor(glm::vec3(-0.5, 0.5,-0.5), glm::vec3(0,0,-1), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

		Vertex3DColor(glm::vec3( 0.5,-0.5, 0.5), glm::vec3(1,0,0), glm::vec3(1, 0, 0)), // Sommet 0 - 0		// RIGHT
		Vertex3DColor(glm::vec3( 0.5,-0.5,-0.5), glm::vec3(1,0,0), glm::vec3(0, 1, 0)), // Sommet 1 - 1
		Vertex3DColor(glm::vec3( 0.5, 0.5,-0.5), glm::vec3(1,0,0), glm::vec3(0, 0, 1)), // Sommet 2 - 2
		Vertex3DColor(glm::vec3( 0.5, 0.5, 0.5), glm::vec3(1,0,0), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

		Vertex3DColor(glm::vec3(-0.5, 0.5, 0.5), glm::vec3(0,1,0), glm::vec3(1, 0, 0)), // Sommet 0 - 0		// TOP
		Vertex3DColor(glm::vec3(-0.5, 0.5,-0.5), glm::vec3(0,1,0), glm::vec3(0, 1, 0)), // Sommet 1 - 1
		Vertex3DColor(glm::vec3( 0.5, 0.5,-0.5), glm::vec3(0,1,0), glm::vec3(0, 0, 1)), // Sommet 2 - 2
		Vertex3DColor(glm::vec3( 0.5, 0.5, 0.5), glm::vec3(0,1,0), glm::vec3(1, 1, 1)), // Sommet 3 - 3 

		Vertex3DColor(glm::vec3(-0.5,-0.5, 0.5), glm::vec3(0,-1,0), glm::vec3(1, 0, 0)), // Sommet 0 - 0		// BOTTOM
		Vertex3DColor(glm::vec3(-0.5,-0.5,-0.5), glm::vec3(0,-1,0), glm::vec3(0, 1, 0)), // Sommet 1 - 1
		Vertex3DColor(glm::vec3( 0.5,-0.5,-0.5), glm::vec3(0,-1,0), glm::vec3(0, 0, 1)), // Sommet 2 - 2
		Vertex3DColor(glm::vec3( 0.5,-0.5, 0.5), glm::vec3(0,-1,0), glm::vec3(1, 1, 1)) // Sommet 3 - 3 

    };

   	GLint nbTriangles = 2 * 6;
    glBufferData(GL_ARRAY_BUFFER, nbTriangles*3 * sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    uint32_t indices[] = {
		 0,  1,  2,  0,  2,  3,
		 4,  5,  6,  4,  6,  7,
		 8,  9, 10,  8, 10, 11,
        12, 13, 14, 12, 14, 15,
        16, 17, 18, 16, 18, 19,
        20, 21, 22, 20, 22, 23,
    };
    GLuint nbIndices = 6* 6;
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


    const GLuint VERTEX_ATTR_MAP_INFOS_FIND = 3;
    glEnableVertexAttribArray(VERTEX_ATTR_MAP_INFOS_FIND);
    glVertexAttribPointer(VERTEX_ATTR_MAP_INFOS_FIND, 1, GL_INT, GL_FALSE, sizeof(GLint), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    ////// SPHERE ////////////:
    Sphere mySphere(0.4, 32, 32);

    GLuint vboSphere;
    glGenBuffers(2, &vboSphere);
    glBindBuffer(GL_ARRAY_BUFFER, vboSphere);
    GLuint nbVertexShere = mySphere.getVertexCount();
    ShapeVertex verticesSphere[nbVertexShere];
    const ShapeVertex *myData = mySphere.getDataPointer();
    int i;
    for (i = 0; i < nbVertexShere; i++){
        verticesSphere[i] = myData[i];
    }

    GLuint nbSphere = 1;
    glBufferData(GL_ARRAY_BUFFER, nbSphere*nbVertexShere*sizeof(ShapeVertex), verticesSphere, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vaoSphere;
    glGenVertexArrays(2, &vaoSphere);  
    glBindVertexArray(vaoSphere);

    glBindBuffer(GL_ARRAY_BUFFER, vboSphere);
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex,position));

    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    const GLuint VERTEX_ATTR_TEX = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_TEX);
    glVertexAttribPointer(VERTEX_ATTR_TEX, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
  
    // Application loop:

    mapProgram.m_Program.use();

			int vals[900] = {1};

	for (i = 0; i < 30*30; i++) {
		vals[i] = 1;
	}


	GLuint loc = glGetUniformLocation(mapProgram.uniformMapFind, "uniformMapFind");
	glUniform1ivARB(loc, 1, vals);



	FreeflyCamera camera (glm::vec3(0, 0,  interface.getMap().getHeight()*0.5));
    glm::mat4 viewMatrix;
	glm::mat4 globalMVMatrix;

	bool movingFront = false;
	bool movingBack = false;
	int turningLeft = 0;
	int turningRight = 0;


	MapType typeGround;

    std::vector<Aleatoirus> aleatoirusList = interface.getListAleatoirus();
    std::vector<Monster> monsterList = interface.getListMonsters();
    
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
    

        glm::mat4 wallMVMatrix = mapMVMatrix;  

        wallProgram.m_Program.use();


        // dessin montagnes
        for (i=0; i < interface.getMap().getWidth(); i++) {
			int j;
			for (j=0; j < interface.getMap().getHeight(); j++) {
				typeGround = interface.getMap().getType(i, j);
				
				if (typeGround == MONTAGNE) {
					if (interface.getMap().getType(i-1, j) == SOL) {
						angle = -M_PI*0.5;
						globalMVMatrix = camera.getViewMatrix();

                        wallMVMatrix = glm::translate(globalMVMatrix, glm::vec3(i-15,  -0.3, j-15));   
						wallMVMatrix = glm::rotate(wallMVMatrix, angle, glm::vec3(0, 1, 0));
 						wallMVMatrix = glm::scale(wallMVMatrix, glm::vec3(1, 0.2, 1));

                        
                       
				        projMatrix = projMatrix;
				        glUniformMatrix4fv(wallProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(wallMVMatrix));
				        glUniformMatrix4fv(wallProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(wallMVMatrix))));
				        glUniformMatrix4fv(wallProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * wallMVMatrix));    
				      	

						glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);
 					} 
                    if (i < interface.getMap().getWidth() && interface.getMap().getType(i+1, j) == SOL) {
 						angle = M_PI*0.5;
 						globalMVMatrix = camera.getViewMatrix();
 						wallMVMatrix = glm::translate(globalMVMatrix, glm::vec3(i-15,  -0.3, j-15));
 						wallMVMatrix = glm::rotate(wallMVMatrix, angle, glm::vec3(0, 1, 0));
 						wallMVMatrix = glm::scale(wallMVMatrix, glm::vec3(1, 0.2, 1));
 						


 				        projMatrix = projMatrix;
 				        glUniformMatrix4fv(wallProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(wallMVMatrix));
 				        glUniformMatrix4fv(wallProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(wallMVMatrix))));
 				        glUniformMatrix4fv(wallProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * wallMVMatrix));    
				      	

 						glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);

 					}
                    if (interface.getMap().getType(i, j-1) == SOL) {
 						globalMVMatrix = camera.getViewMatrix();
 						wallMVMatrix = glm::translate(globalMVMatrix, glm::vec3(i-15,  -0.3, j-15));
 						wallMVMatrix = glm::scale(wallMVMatrix, glm::vec3(1, 0.2, 1));


 						projMatrix = projMatrix;
 						glUniformMatrix4fv(wallProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(wallMVMatrix));
 						glUniformMatrix4fv(wallProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(wallMVMatrix))));
 						glUniformMatrix4fv(wallProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * wallMVMatrix));    
				      	

 						glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);
 					} 
 					if (j < interface.getMap().getHeight() && interface.getMap().getType(i, j+1) == SOL) {
 						globalMVMatrix = camera.getViewMatrix();

 						wallMVMatrix = glm::translate(globalMVMatrix, glm::vec3(i-15, -0.3, j-15));
 						wallMVMatrix = glm::scale(wallMVMatrix, glm::vec3(1, 0.2, 1));

				        projMatrix = projMatrix;
 				        glUniformMatrix4fv(wallProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(wallMVMatrix));
 				        glUniformMatrix4fv(wallProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(wallMVMatrix))));
 				        glUniformMatrix4fv(wallProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * wallMVMatrix));    

 						glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);
 					} 

				}
			}
		}





		glBindVertexArray(0);
		


		vals[i] = 1;

		GLuint loc = glGetUniformLocation(mapProgram.uniformMapFind, "uniformMapFind");
		glUniform1ivARB(loc, 1,vals);
		


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
        for (i=0; i < aleatoirusList.size(); i++){

            //AMELIORER PLACEMENT ALEA Z
           // glm::mat4 aleaMVMatrix = glm::translate(globalMVMatrix, glm::vec3((-0.5 + aleatoirusList.at(i).getPosition().x*0.01)*interface.getMap().getWidth() - 0.45, -0.49, (-0.5 + aleatoirusList.at(i).getPosition().y*0.03)*interface.getMap().getHeight() - 0.1 ) );
            glm::mat4 aleaMVMatrix = glm::translate(globalMVMatrix, glm::vec3(aleatoirusList.at(i).getPosition().x - - interface.getMap().getWidth()*0.5, -0.49, aleatoirusList.at(i).getPosition().y - - interface.getMap().getHeight()*0.5 - .5)); 
            aleaMVMatrix = glm::rotate(aleaMVMatrix, angle, glm::vec3(1, 0, 0));
            aleaMVMatrix = glm::scale(aleaMVMatrix, glm::vec3(0.01*interface.getMap().getWidth(), 0.03*interface.getMap().getHeight(), 0));


            projMatrix = projMatrix;
            glUniformMatrix4fv(aleatoirusProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(aleaMVMatrix));
            glUniformMatrix4fv(aleatoirusProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(aleaMVMatrix))));
            glUniformMatrix4fv(aleatoirusProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * aleaMVMatrix));    

            glDrawElements(GL_TRIANGLES, 2*3, GL_UNSIGNED_INT, 0);
        }
        
       
        glBindVertexArray(0);

        // MONSTER DRAWING //
        glBindVertexArray(2);   
        monsterProgram.m_Program.use();
        for (i=0; i < monsterList.size(); i++){
            // glm::mat4 monsterMVMatrix = glm::translate(globalMVMatrix, glm::vec3((-0.5 + monsterList.at(i).getPosition().x*0.01)*interface.getMap().getWidth() - 0.45, 0, (-0.5 + monsterList.at(i).getPosition().y*0.03)*interface.getMap().getHeight() - 0.1 ) );
            glm::mat4 monsterMVMatrix = glm::translate(globalMVMatrix, glm::vec3( monsterList.at(i).getPosition().x - interface.getMap().getWidth()*0.5, 0, monsterList.at(i).getPosition().y - interface.getMap().getHeight()*0.5 ) );
            monsterMVMatrix = glm::scale(monsterMVMatrix, glm::vec3(0.5, 0.5, 0.5));

            projMatrix = projMatrix;
            glUniformMatrix4fv(monsterProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(monsterMVMatrix));
            glUniformMatrix4fv(monsterProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(monsterMVMatrix))));
            glUniformMatrix4fv(monsterProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * monsterMVMatrix));    
            glDrawArrays(GL_TRIANGLES, 0, nbVertexShere);

            if (interface.collisionMonster(i)) {

            	glBindVertexArray(0);
            	glBindVertexArray(1);

            	cout << "ATTENTION J'ATTAQUE !!!!" << endl;
      			glDrawElements(GL_TRIANGLES, nbTriangles*3, GL_UNSIGNED_INT, 0);

            	glBindVertexArray(2);   

            }

        }
        glBindVertexArray(0);

        if (turningRight >= TURNING_VAL) {
            camera.rotateLeft(-TURNING_VAL);
            turningRight -= TURNING_VAL;
        }
    
        if (turningLeft >= TURNING_VAL) {
            camera.rotateLeft(TURNING_VAL);
            turningLeft -= TURNING_VAL;
        }


       

        if (movingFront == true  && turningRight < 5 && turningLeft < 5) {

        	if (abs(camera.getPosition().x) - interface.getMap().getWidth() * 0.5 <= 0 && abs(camera.getPosition().z) - interface.getMap().getWidth() * 0.5  <= 0) {
				camera.moveFront(1);

	        	typeGround = interface.getMap().getType(camera.getPosition().x+ 15, camera.getPosition().z + 15);
	        	cout << interface.getMap().fromEnumToString(interface.getMap().getType(camera.getPosition().x + 15, camera.getPosition().z + 15)) << endl;

	        	if (typeGround != MONTAGNE) {
	    	            // camera.moveFront(0.5);
		           
		        } else {
	                camera.moveFront(-1);
		        	movingFront = false;
		       	}

	       	} else {
	            	movingFront = false;
	                camera.moveFront(-1);
			}

            cout << "cam X : " << camera.getPosition().x << endl;
            cout << "cam Y : " << camera.getPosition().z << endl;
        }
        if (movingBack == true && turningRight < 5 && turningLeft < 5) {	//encore des problemes

        
        	if (abs(camera.getPosition().x) - interface.getMap().getWidth() * 0.5 <= 0 && abs(camera.getPosition().z) - interface.getMap().getWidth() * 0.5  <= 0) {
				camera.moveFront(-1);

	        	typeGround = interface.getMap().getType(camera.getPosition().x + 15, camera.getPosition().z  + 15);

	        	if (typeGround != MONTAGNE) {
		           
		        } else {
	                camera.moveFront(1);
		        	movingFront = false;
		       	}

	       	} else {
	            	movingFront = false;
	                camera.moveFront(1);
			}
        }

        interface.player.setPosition(glm::vec2(camera.getPosition().x, camera.getPosition().z));
        interface.collision();
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
                    turningRight += 90;
                }
                else if(e.key.keysym.sym == SDLK_LEFT) {
                    turningLeft += 90;
                }
                else if(e.key.keysym.sym == SDLK_DOWN) {
                    movingBack = true;
                }
                break;

            
            case SDL_KEYUP:

                if(e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym == SDLK_UP) {
                    movingFront = false;
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
