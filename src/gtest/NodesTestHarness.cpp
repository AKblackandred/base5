#include <limits.h>
#include <math.h>
#include "gtest/gtest.h"

#include "NodesTestHarness.hpp"
#include "Nodes.hpp"
#include "Node.hpp"
#include "SceneExceptions.hpp"

#include <iostream>
#include <fstream>
#include <thread>

/* Reference: http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html */

NodesTestHarness::NodesTestHarness()
{
  nodes = nullptr;
}

NodesTestHarness::~NodesTestHarness()
{
  nodes.reset();
}

void NodesTestHarness::SetUp()
{
  this->nodes.reset(new Nodes());
}

void NodesTestHarness::TearDown()
{
  this->nodes.reset();
  this->nodes = nullptr;
}

TEST_F(NodesTestHarness,constructor_noArgs)
{ 
  EXPECT_EQ(nodes->getNodeCount(), 0);

  EXPECT_THROW(nodes->getNode(0),NodeIndexOutOfRange);
}

TEST_F(NodesTestHarness,testAddNode) 
{
  EXPECT_EQ(nodes->getNodeCount(), 0);

  shared_ptr<Node> test(new Node());

  nodes->addNode(test);

  EXPECT_EQ(nodes->getNodeCount(), 1);

  EXPECT_EQ(nodes->getNode(0), test);
}