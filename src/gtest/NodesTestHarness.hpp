#ifndef NODESTESTHARNESS_H_
#define NODESTESTHARNESS_H_

#include <limits.h>
#include <gtest/gtest.h>

#include "Nodes.hpp"


#include <memory>
using std::shared_ptr;

class NodesTestHarness : public ::testing::Test
{
protected:

  virtual void SetUp();
  virtual void TearDown();

  shared_ptr<Nodes> nodes;

public:

    NodesTestHarness();
    virtual ~NodesTestHarness();
};

#endif // SCENETESTHARNESS_H_
