
#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class PrincipleAxesModel {

private:

	glm::vec3				pos = glm::vec3(0.0f, 0.0f, 0.0f); //position


	GLuint					paVertexArrayObj;

	GLuint					paVertexBuffer;
	GLuint					paColourBuffer;

	GLuint					paIndexBuffer;

	GLuint					paShader;

public:

	PrincipleAxesModel();

	~PrincipleAxesModel();

	void render(const glm::mat4& T);

	//accessor methods
	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);

};
