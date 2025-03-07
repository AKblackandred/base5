#include "Scene.hpp"

#include "Nodes.hpp"

Scene::Scene()
{
    formatVersion = "NOT_SET";
    sceneManager = "NOT_SET";
    minOgreVersion = "NOT_SET";
    author = "NOT_SET";
    id = -1;
    nodes = nullptr;
}


Scene::~Scene()
{
    nodes.reset();
    nodes = nullptr;
}

void Scene::setFormatVersion(std::string formatVersion)
{
    this->formatVersion = formatVersion;
}

std::string Scene::getFormatVersion()
{
    return formatVersion;
}

void Scene::setSceneManager(std::string sceneManager)
{
    this->sceneManager = sceneManager;
}

std::string Scene::getSceneManager()
{
    return sceneManager;
}

void Scene::setMinOgreVersion(std::string minOgreVersion)
{
    this->minOgreVersion = minOgreVersion;
}

std::string Scene::getMinOgreVersion()
{
    return minOgreVersion;
}

void Scene::setAuthor(std::string author)
{
    this->author = author;
}

std::string Scene::getAuthor()
{
    return this->author;
}

void Scene::setID(int id)
{
    this->id = id;
}

int Scene::getID()
{
    return id;
}

void Scene::addNodes(std::shared_ptr<Nodes> nodes)
{
    this->nodes = nodes;
}

std::shared_ptr<Nodes> Scene::getNodes()
{
    return nodes;
}
