#ifndef VECTOR_HPP
#define VECTOR_HPP


struct Vertex2DColor {
    glm::vec2 position;
    glm::vec3 color;
    Vertex2DColor(){}
    Vertex2DColor (glm::vec2 p, glm::vec3 c){
        position = p;
        color = c;
    }
};


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

#endif