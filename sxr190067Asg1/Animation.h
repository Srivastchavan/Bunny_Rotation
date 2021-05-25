#pragma once

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/******************************************************************************
* Written by Srivastchavan Rengarajan starting September 03, 2020.
******************************************************************************/

class Animation
{
public:
	
	int Angle_a = 45;
	int Angle_b = 45;
	float New_Angle_a;
	float New_Angle_b;

	Animation();
	~Animation();

	void init();
	void update(float delta_time);

	void reset();
	void rotateLocalX();
	void rotateGlobalY();

	glm::vec3 locAxisX = glm::vec3(1, 0, 0);
	glm::vec3 glbAxisY = glm::vec3(0, 1, 0);
	glm::vec3 oldVector = glm::vec3(5.0, 0.0, 0.0);
	glm::vec3 newVector = oldVector;

	glm::mat3 locMatrix = glm::mat3();
	glm::mat3 glbMatrix = glm::mat3();
	glm::mat3 newMatrix = glm::mat3();

	glm::mat4 rotated_model_mat;
	glm::mat4 get_model_mat() { return m_model_mat; };

private:
	glm::mat4 m_model_mat;
};

/******************************************************************************
* Code Changes end
******************************************************************************/
