#include "Light.h"

Light::Light()
{
	type = "not set";
}

Light::~Light()
{
}

void Light::setType(std::string& type)
{
	type = type;
}

std::string& Light::getType()
{
	return type;
}
