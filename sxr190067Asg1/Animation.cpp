#include "Animation.h"

Animation::Animation()
{
	this->m_model_mat = glm::mat4(1.0f);
}

Animation::~Animation()
{
}

void Animation::init()
{
	reset();
}

void Animation::update(float delta_time)
{
}

/******************************************************************************
* Written by Srivastchavan Rengarajan starting September 03, 2020.
******************************************************************************/

void Animation::reset()
{
	New_Angle_a = 0;
	New_Angle_b = 0;
	
	oldVector = glm::vec3(5.0f, 0.0f, 0.0f);
	newVector = oldVector;
	
	locMatrix = glm::mat3();
	glbMatrix = glm::mat3();

	m_model_mat = glm::mat4(1.0f);
	m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0f, 0.0f, 0.0f));
}

void Animation::rotateLocalX()
{
	New_Angle_a += (float)Angle_a;
	rotated_model_mat = glm::mat4();

	float sin_Angle_a = glm::sin(glm::radians(-New_Angle_a));
	float cos_Angle_a = glm::cos(glm::radians(-New_Angle_a));

	float locArr[9] = { 1,	0,				0,
						0,	cos_Angle_a,	-sin_Angle_a,
						0,	sin_Angle_a,	cos_Angle_a};

	locMatrix = glm::make_mat3(locArr);

	rotated_model_mat = glm::translate(rotated_model_mat, newVector);
	rotated_model_mat = glm::rotate(rotated_model_mat, glm::radians(New_Angle_b), glbAxisY);
	
	m_model_mat = glm::rotate(rotated_model_mat, glm::radians(New_Angle_a), locAxisX);
	rotated_model_mat = m_model_mat;
}

void Animation::rotateGlobalY()
{
	New_Angle_b += (float)Angle_b;
	rotated_model_mat = glm::mat4();

	float sin_Angle_b = glm::sin(glm::radians(New_Angle_b));
	float cos_Angle_b = glm::cos(glm::radians(New_Angle_b));

	float glbArr[9] = { cos_Angle_b,	0,	-sin_Angle_b,
						0,				1,	0,
						sin_Angle_b,	0,	cos_Angle_b };

	glbMatrix = glm::make_mat3(glbArr);
	newVector = glbMatrix * oldVector;

	rotated_model_mat = glm::translate(rotated_model_mat, newVector);
	rotated_model_mat = glm::rotate(rotated_model_mat, glm::radians(New_Angle_b), glbAxisY);

	m_model_mat = glm::rotate(rotated_model_mat, glm::radians(New_Angle_a), locAxisX);
	rotated_model_mat = m_model_mat;
}

/******************************************************************************
* Code Changes end
******************************************************************************/
