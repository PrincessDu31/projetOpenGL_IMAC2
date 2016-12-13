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
			m_UpVector = m_FrontVector * m_LeftVector; 
		}
		

	public: 
		FreeflyCamera () {
			m_Position = (glm::vec3(0,M_PI,20));
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
		}
		void rotateUp(float angle_degre) {
			m_fTheta += radians(angle_degre);
		}

		glm::mat4 getViewMatrix() const {
			glm::mat4 ViewMatrix = glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector); 
			return ViewMatrix;
		}


	};

}