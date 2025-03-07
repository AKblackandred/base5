#ifndef TINYXMLPROTOYPTETESTHARNESS_H_
#define TINYXMLPROTOYPTETESTHARNESS_H_

#include <limits.h>
#include <gtest/gtest.h>

#include "TinyXMLPrototype.hpp"

#include <memory>
using std::shared_ptr;

class TinyXMLPrototypeTestHarness : public ::testing::Test
{
protected:

  virtual void SetUp();
  virtual void TearDown();

  shared_ptr<TinyXMLPrototype> txp;

public:

    TinyXMLPrototypeTestHarness();
    virtual ~TinyXMLPrototypeTestHarness();
};

#endif // TINYXMLPROTOYPTETESTHARNESS_H_
