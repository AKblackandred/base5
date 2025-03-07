#ifndef RANDOM_GEN_TEST_HARNESS_H_
#define RANDOM_GEN_TEST_HARNESS_H_

#include <limits.h>
#include <gtest/gtest.h>

#include "RandGen.h"
using Maths::RandGen;

#include <memory>
using std::shared_ptr;

class RandomGenTestHarness : public ::testing::Test
{
protected:

  virtual void SetUp();
  virtual void TearDown();

  shared_ptr<RandGen> rg;

public:

    RandomGenTestHarness();
    virtual ~RandomGenTestHarness();
};

#endif // RANDOM_GEN_TEST_HARNESS_H_
