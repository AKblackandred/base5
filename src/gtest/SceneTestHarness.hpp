#ifndef SCENETESTHARNESS_H_
#define SCENETESTHARNESS_H_

#include <limits.h>
#include <gtest/gtest.h>

#include "Scene.hpp"


#include <memory>
using std::shared_ptr;

class SceneTestHarness : public ::testing::Test
{
protected:

  virtual void SetUp();
  virtual void TearDown();

  shared_ptr<Scene> scn;

public:

    SceneTestHarness();
    virtual ~SceneTestHarness();
};

#endif // SCENETESTHARNESS_H_
