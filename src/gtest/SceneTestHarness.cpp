#include <limits.h>
#include <math.h>
#include "gtest/gtest.h"

#include "SceneTestHarness.hpp"
#include "Scene.hpp"

#include <iostream>
#include <fstream>
#include <thread>

/* Reference: http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html */

SceneTestHarness::SceneTestHarness()
{
  scn = nullptr;
}

SceneTestHarness::~SceneTestHarness()
{
  scn.reset();
}

void SceneTestHarness::SetUp()
{
  this->scn.reset(new Scene());
}

void SceneTestHarness::TearDown()
{
  this->scn.reset();
  this->scn = nullptr;
}

TEST_F(SceneTestHarness,constructor_noArgs)
{ 
  EXPECT_STREQ(scn->getAuthor().c_str(), "NOT_SET");

  std::string not_set("NOT_SET");

  EXPECT_EQ(scn->getFormatVersion().compare(not_set), 0);
}

TEST_F(SceneTestHarness,getAuthorTest)
{ 
  EXPECT_STREQ(scn->getAuthor().c_str(), "NOT_SET");
}

TEST_F(SceneTestHarness,setAuthorTest)
{ 
  EXPECT_STREQ(scn->getAuthor().c_str(), "NOT_SET");

  scn->setAuthor("Bob");

  EXPECT_STREQ(scn->getAuthor().c_str(), "Bob");
}

