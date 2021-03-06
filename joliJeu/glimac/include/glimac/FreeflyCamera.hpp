#pragma once
#include <math.h>

namespace glimac {

	class FreeflyCamera {
	private:
		glm::vec3 m_Position;
		float m_fPhi;
		float m_fTheta;
		glm::vec3 m_FrontVector;
		glm::vec3 m_LeftVector; 
		glm::vec3 m_UpVector;

		void computeDirectionVectors() {
			m_FrontVector = glm::vec3(cos(m_fTheta) * sin(m_fPhi), sin(m_fTheta), cos(m_fTheta) * cos(m_fPhi));
			m_LeftVector = glm::vec3(sin(m_fPhi+(M_PI * 0.5)), 0, cos(m_fPhi+(M_PI * 0.5)));
			m_UpVector =  glm::cross(m_FrontVector, m_LeftVector); 
		}
		

	public: 
		FreeflyCamera () {
			m_Position = (glm::vec3(0, 0,0));
			m_fPhi = M_PI;
			m_fTheta = 0;
			computeDirectionVectors();
		}

		FreeflyCamera (glm::vec3 pos) {
			m_Position = pos;
			m_fPhi = M_PI;
			m_fTheta = 0;
			computeDirectionVectors();
		}

		void moveLeft(float t) {
			m_Position += t*m_LeftVector;
		}

		void moveFront(float t) {
			m_Position += t*m_FrontVector;
		}

		float radians (float degre) const {
			return (degre * M_PI / 180.0);
		}

		void rotateLeft(float angle_degre) {
			m_fPhi += radians(angle_degre);
			computeDirectionVectors();
		}
		void rotateUp(float angle_degre) {
			m_fTheta += radians(angle_degre);
			computeDirectionVectors();

		}

		glm::mat4 getViewMatrix() const {
			glm::mat4 ViewMatrix = glm::lookAt(m_Position, m_Position + m_FrontVector, glm::cross(m_FrontVector, m_LeftVector)); 
			return ViewMatrix;
		}

		glm::vec3 getPosition () const {
			float xTmp = m_Position.x;
			float yTmp = m_Position.y;
			float zTmp = m_Position.z;
			return glm::vec3 (xTmp, yTmp, zTmp);
		}

		glm::vec3 getDirectionFront () const {
			float xTmp = floor(m_FrontVector.x);
			float yTmp = floor(m_FrontVector.y);
			float zTmp = floor(m_FrontVector.z);
			return glm::vec3 (xTmp, yTmp, zTmp);
		}

		glm::vec3 getDirectionLeft () const {
			float xTmp = floor(m_LeftVector.x);
			float yTmp = floor(m_LeftVector.y);
			float zTmp = floor(m_LeftVector.z);
			return glm::vec3 (xTmp, yTmp, zTmp);
		}

		glm::vec3 getDirectionUp () const {
			float xTmp = floor(m_UpVector.x);
			float yTmp = floor(m_UpVector.y);
			float zTmp = floor(m_UpVector.z);
			return glm::vec3 (xTmp, yTmp, zTmp);
		}


	};

}