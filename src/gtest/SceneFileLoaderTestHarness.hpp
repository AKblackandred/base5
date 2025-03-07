#ifndef SCENEFILELOADERTESTHARNESS_HPP_
#define SCENEFILELOADERTESTHARNESS_HPP_

#include <limits.h>
#include <gtest/gtest.h>

#include "SceneFileLoader.hpp"

#include <memory>
using std::shared_ptr;

class SceneFileLoaderTestHarness : public ::testing::Test
{
protected:

  virtual void SetUp();
  virtual void TearDown();

  shared_ptr<SceneFileLoader> sfl;

public:

    SceneFileLoaderTestHarness();
    virtual ~SceneFileLoaderTestHarness();
};

#endif // SCENEFILELOADERTESTHARNESS_HPP_
