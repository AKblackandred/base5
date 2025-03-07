#ifndef SCENEFILELOADER_HPP
#define SCENEFILELOADER_HPP

#include <string>

#include "tinyxml2.h"

#include <memory>

class Scene;
class Nodes;
class Node;
class Entity;

namespace Maths {
	class Vector3;
}


class SceneFileLoader
{
public:
	SceneFileLoader();
	virtual ~SceneFileLoader();

	void setFilename(const std::string& filename);
	void openFile();

	void parse();

	std::shared_ptr<Scene> getScene() const;
private:
	std::string filename;
	std::shared_ptr<Scene> scene;
	std::shared_ptr<tinyxml2::XMLElement> root;

	void parseScene(std::shared_ptr<tinyxml2::XMLElement> scene);
	std::shared_ptr<Nodes> parseNodes(std::shared_ptr<tinyxml2::XMLElement> nodes);
	std::shared_ptr<Node> parseNode(std::shared_ptr<tinyxml2::XMLElement> node);
	std::shared_ptr<Maths::Vector3> parsePosition(std::shared_ptr<tinyxml2::XMLElement> position);
	std::shared_ptr<Entity> parseEntity(std::shared_ptr<tinyxml2::XMLElement> entity);
	
	// Needs to be in scope while the file is being
	// parsed
	tinyxml2::XMLDocument doc;
};

#endif // SCENEFILEEDITOR_HPP