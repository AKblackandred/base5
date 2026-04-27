#ifndef SCENEFILETREEVIEW_H
#define SCENEFILETREEVIEW_H

#include <string>

#include "tinyxml2.h"
#include <wx/wx.h>
#include <wx/treectrl.h>

#include <memory>

#include "Scene.hpp"
#include "Nodes.hpp"
#include "Node.hpp"
#include "Entity.hpp"
#include "Light.h"

class SceneFileTreeView
{
private:

public:

	static void buildTree(std::shared_ptr<Scene> scene, wxTreeCtrl* treeView);

};

#endif