#pragma once
#include <math.hpp>

namespace glimac {

	class TrackballCamera {
	private:
		float m_fDistance;
		float m_fAngleX;
		float m_fAngleY;
	public: 
		TrackballCamera(){
			m_fAngleY = 0;
			m_fAngleX = 0;
			m_fDistance = 5;
		}
		void moveFront(float delta) {
			m_fDistance += delta;
		}
		void rotateLeft(float degrees) {
			m_fAngleX += degrees;
		}
		void rotateUp(float degrees) {
			m_fAngleY += degrees;
		}

		float radians (float degre) {
			return (degre * m_pi / 180.0);
		}

		glm::mat4 getViewMatrix() const {
			glm::mat4 ViewMatrix = glm::translate(glm::mat4(1), glm::vec3(0,0,-m_fDistance))*
									glm::rotation(glm::mat4(1), radians(rotateLeft), glm::vec3(1,0,0))*
									glm::rotation(glm::mat4(1), radians(rotateUp), glm::vec3(0,1,0)); 
		}

	};

}