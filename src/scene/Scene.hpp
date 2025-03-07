#ifndef SCENE_H_
#define SCENE_H_

#include <string>

#include <memory>

class Nodes;

class Scene 
{
    public:
        Scene();
        ~Scene();

        void setFormatVersion(std::string formatVersion);
        std::string getFormatVersion();

        void setSceneManager(std::string formatSceneManager);
        std::string getSceneManager();

        void setMinOgreVersion(std::string minOgreVersion);
        std::string getMinOgreVersion();

        void setAuthor(std::string minAuthor);
        std::string getAuthor();

        void setID(int id);
        int getID();

        void addNodes(std::shared_ptr<Nodes> nodes);
        std::shared_ptr<Nodes> getNodes();

    private:
        // Note: fixed at 1.1
        std::string formatVersion;
        int id;
        std::string sceneManager;
        std::string minOgreVersion;
        std::string author;

        std::shared_ptr<Nodes> nodes;
};

#endif
