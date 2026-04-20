#include "Light.h"

Light::Light()
{
	type = "not set";
	colourDiffuse = nullptr;
	colourSpecular = nullptr;
}

Light::~Light()
{
	colourDiffuse.reset();
	colourSpecular.reset();
}

void Light::setType(std::string& type)
{
	type = type;
}

std::string& Light::getType()
{
	return type;
}

void Light::setColourDiffuse(std::shared_ptr<Maths::Vector3> colourDiffuse)
{
	this->colourDiffuse = colourDiffuse;
}

std::shared_ptr<Maths::Vector3> Light::getColourDiffuse()
{
	return colourDiffuse;
}

void Light::setColourSpecular(std::shared_ptr<Maths::Vector3> colourSpecular)
{
	this->colourSpecular = colourSpecular;
}

std::shared_ptr<Maths::Vector3> Light::getColourSpecular()
{
	return colourSpecular;
}