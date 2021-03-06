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

struct Vertex {
        glm::vec3 m_Position;
        glm::vec3 m_Normal;
        glm::vec2 m_TexCoords;
        Vertex(){}
        Vertex(glm::vec3 p, glm::vec3 n, glm::vec2 t){
        m_Position = p;
        m_Normal = n;
        m_TexCoords = t;
    }
    };

#endif