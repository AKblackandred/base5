#include <limits.h>
#include <math.h>
#include "gtest/gtest.h"

#include "SceneFileLoaderTestHarness.hpp"
#include "SceneFileLoader.hpp"
#include "Scene.hpp"
#include "LoaderExceptions.hpp"
#include "Nodes.hpp"
#include "Node.hpp"
#include "Entity.hpp"
#include "Vector3.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <string>

/* Reference: http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html */

SceneFileLoaderTestHarness::SceneFileLoaderTestHarness()
{
    sfl = nullptr;
}

SceneFileLoaderTestHarness::~SceneFileLoaderTestHarness()
{
    sfl.reset();
}

void SceneFileLoaderTestHarness::SetUp()
{
    this->sfl.reset(new SceneFileLoader());
}

void SceneFileLoaderTestHarness::TearDown()
{
    this->sfl.reset();
    this->sfl = nullptr;
}

TEST_F(SceneFileLoaderTestHarness,constructor_noArgs)
{
    // Check defaults are set
    // Check defaults
    //EXPECT_STREQ(txp->getFilename().c_str(), "not set");
}

TEST_F(SceneFileLoaderTestHarness, testDiscReadWrite) 
{
    /*
    std::string filename = "..\\testfiles\\ProfileContourDS.mat";
    string cwd = std::filesystem::current_path().string();
    filename = cwd + "\\" + filename;
    */
   std::string myText;
   std::string testString = "My text for testing";

    std::ofstream outfile ("../testfiles/test.txt");

    EXPECT_TRUE(outfile.is_open());

    outfile << testString << std::endl;

    outfile.close();

    std::ifstream infile("../testfiles/test.txt");

    EXPECT_TRUE(infile.is_open());

    // Read back the line
    getline (infile, myText);

    EXPECT_TRUE(myText == testString);

    // Close the file
    infile.close();
}

TEST_F(SceneFileLoaderTestHarness, parseSceneTest)
{
    std::string testFile("testfiles/extendedTest.scene");
    sfl->setFilename(testFile);

    sfl->openFile();

    sfl->parse();

    std::shared_ptr<Scene> scene = sfl->getScene();

    EXPECT_STREQ(scene->getFormatVersion().c_str(), "1.1");

    std::shared_ptr<Nodes> nodes = scene->getNodes();

    EXPECT_EQ(nodes->getNodeCount(), 2);

    std::shared_ptr<Node> node = nodes->getNode(0);

    // should be robot.mesh
    std::shared_ptr<Entity> entity = node->getEntity();

    EXPECT_STREQ(entity->getMeshfile().c_str(), "robot.mesh");
}

TEST_F(SceneFileLoaderTestHarness, parseSceneTestNoFile)
{
    std::string testFile("testfiles/does_not_exist.scene");
    sfl->setFilename(testFile);

    EXPECT_THROW(sfl->openFile(), DocumentLoadFailed);

}
