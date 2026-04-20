#include "SceneFileLoader.hpp"
#include "NoOppDeleter.hpp"
#include "Scene.hpp"
#include "Nodes.hpp"
#include "Node.hpp"
#include "Entity.hpp"
#include "Vector3.h"
#include "Quaternion.h"
#include "Light.h"
#include <string>

#include "LoaderExceptions.hpp"

SceneFileLoader::SceneFileLoader()
{
	root = nullptr;
}

SceneFileLoader::~SceneFileLoader()
{
	root.reset();
}

void SceneFileLoader::setFilename(const std::string& filename)
{
	this->filename = filename;
}

void SceneFileLoader::openFile()
{
	doc.LoadFile(filename.c_str());

	if (doc.ErrorID() != 0)
	{
		throw DocumentLoadFailed();
	}

	root = std::shared_ptr<tinyxml2::XMLElement>(doc.RootElement(), NoOppDeleter());
}

void SceneFileLoader::parse()
{
	if (root == nullptr)
	{
		throw RootParseFailed();
	}

	parseScene(root);

	std::shared_ptr<tinyxml2::XMLElement> nodes(root->FirstChildElement("nodes"), NoOppDeleter());

	std::shared_ptr<Nodes> nodesObject = parseNodes(nodes);

	scene->addNodes(nodesObject);
}

std::shared_ptr<Scene> SceneFileLoader::getScene() const
{
	return this->scene;
}

void SceneFileLoader::parseScene(std::shared_ptr<tinyxml2::XMLElement> sceneElement)
{
	scene = std::shared_ptr<Scene>(new Scene());

	std::string version = sceneElement->Attribute("formatVersion");

	scene->setFormatVersion(version);
}

std::shared_ptr<Nodes> SceneFileLoader::parseNodes(std::shared_ptr<tinyxml2::XMLElement> nodes)
{
	std::shared_ptr<Nodes>nodesObject(new Nodes());

	//int totalChildren = nodes->ChildElementCount();

	std::shared_ptr<tinyxml2::XMLElement> nodesChild(nodes->FirstChildElement(), NoOppDeleter());

	while(nodesChild != NULL)
	{
		if(std::string(nodesChild->Name()).compare("node") == 0)
        {
            std::shared_ptr<Node> newNode = parseNode(nodesChild);
            nodesObject->addNode(newNode);
        }
		else 
		{
			// from the .dtd file - nodes element has an optional position
			// since we have the code to parse that from node, adding this
			// is kind of free. 
			if(std::string(nodesChild->Name()).compare("position") == 0)
        	{
				std::shared_ptr<Maths::Vector3> pos = parsePosition(nodesChild);
				nodesObject->setPosition(pos);
			}
		}

		nodesChild.reset(nodesChild->NextSiblingElement(), NoOppDeleter());
	}

	return nodesObject;
}

std::shared_ptr<Node> SceneFileLoader::parseNode(std::shared_ptr<tinyxml2::XMLElement> node)
{
	std::shared_ptr<Node>nodeObject(new Node());

	std::shared_ptr<tinyxml2::XMLElement> nodeChild(node->FirstChildElement(), NoOppDeleter());

	while(nodeChild != NULL)
	{
		if(std::string(nodeChild->Name()).compare("node") == 0)
        {
            std::shared_ptr<Node> newNode = parseNode(nodeChild);
            nodeObject->setChildNode(newNode);
        }
		else
		{
			if (std::string(nodeChild->Name()).compare("position") == 0)
			{
				std::shared_ptr<Maths::Vector3> pos = parsePosition(nodeChild);
				nodeObject->setPosition(pos);
			}
			else
			{
				if (std::string(nodeChild->Name()).compare("entity") == 0)
				{
					std::shared_ptr<Entity> ent = parseEntity(nodeChild);
					nodeObject->setEntity(ent);
				}
				else
				{
					if (std::string(nodeChild->Name()).compare("scale") == 0)
					{
						std::shared_ptr<Maths::Vector3> scale = parseScale(nodeChild);
						nodeObject->setScale(scale);
					}
					else
					{
						if (std::string(nodeChild->Name()).compare("Rotation") == 0)
						{
							std::shared_ptr<Maths::Quaternion> rotation = parseRotation(nodeChild);
							nodeObject->setRotation(rotation);
						}
						else
						{
							if (std::string(nodeChild->Name()).compare("light") == 0)
							{
								std::shared_ptr<Light> light = parseLight(nodeChild);
								nodeObject->setLight(light);
							}
						}
					}
				}
			}
		}
		nodeChild.reset(nodeChild->NextSiblingElement(), NoOppDeleter());
	}	

	return nodeObject;
}

std::shared_ptr<Maths::Vector3> SceneFileLoader::parsePosition(std::shared_ptr<tinyxml2::XMLElement> position)
{
	std::shared_ptr<Maths::Vector3>pos(new Maths::Vector3());

	float x, y, z;

	x = position->FloatAttribute("x");
	y = position->FloatAttribute("y");
	z = position->FloatAttribute("z");

	pos->Set(x, y, z);

	return pos;
}


std::shared_ptr<Entity> SceneFileLoader::parseEntity(std::shared_ptr<tinyxml2::XMLElement> entity)
{
	std::shared_ptr<Entity>ent(new Entity());

	std::string meshfile = entity->Attribute("meshFile");

	ent->setMeshfile(meshfile);

	return ent;
}

std::shared_ptr<Maths::Vector3> SceneFileLoader::parseScale(std::shared_ptr<tinyxml2::XMLElement> position)
{
	std::shared_ptr<Maths::Vector3>scale(new Maths::Vector3());

	float x, y, z;

	x = position->FloatAttribute("x");
	y = position->FloatAttribute("y");
	z = position->FloatAttribute("z");

	scale->Set(x, y, z);

	return scale;
}

std::shared_ptr<Maths::Quaternion> SceneFileLoader::parseRotation(std::shared_ptr<tinyxml2::XMLElement> rotation)
{
	std::shared_ptr<Maths::Quaternion>SetRotation(new Maths::Quaternion());

	float qx, qy, qz, qw;

	qx = rotation->FloatAttribute("qx");
	qy = rotation->FloatAttribute("qy");
	qz = rotation->FloatAttribute("qz");
	qw = rotation->FloatAttribute("qw");

	SetRotation->Set(qx, qy, qz, qw);

	return SetRotation;
}

std::shared_ptr<Maths::Vector3> SceneFileLoader::parseColourDiffuse(std::shared_ptr<tinyxml2::XMLElement> colourDiffuse)
{
	std::shared_ptr<Maths::Vector3>colour(new Maths::Vector3());

	float r, g, b;

	r = colourDiffuse->FloatAttribute("r");
	g = colourDiffuse->FloatAttribute("g");
	b = colourDiffuse->FloatAttribute("b");

	colour->Set(r, g, b);

	return colour;
}

std::shared_ptr<Maths::Vector3> SceneFileLoader::parseColourSpecular(std::shared_ptr<tinyxml2::XMLElement> colourSpecular)
{
	std::shared_ptr<Maths::Vector3>colour(new Maths::Vector3());

	float r, g, b;

	r = colourSpecular->FloatAttribute("r");
	g = colourSpecular->FloatAttribute("g");
	b = colourSpecular->FloatAttribute("b");

	colour->Set(r, g, b);

	return colour;
}

std::shared_ptr<Light> SceneFileLoader::parseLight(std::shared_ptr<tinyxml2::XMLElement> light)
{
	std::shared_ptr<Light>lightObject(new Light());

	std::string type = light->Attribute("type");

	lightObject->setType(type);

	std::shared_ptr<tinyxml2::XMLElement> lightChild(light->FirstChildElement(), NoOppDeleter());

	while (lightChild != NULL)
		if (std::string(lightChild->Name()).compare("colourDiffuse") == 0)
		{
			std::shared_ptr<Maths::Vector3> colourDiffuse = parseColourDiffuse(lightChild);
			lightObject->setColourDiffuse(colourDiffuse);
		}
		else
		{
			if (std::string(lightChild->Name()).compare("colourSpecular") == 0)
			{
				std::shared_ptr<Maths::Vector3> colourSpecular = parseColourSpecular(lightChild);
				lightObject->setColourSpecular(colourSpecular);
			}

			lightChild.reset(lightChild->NextSiblingElement(), NoOppDeleter());
		}
	return lightObject;
}
