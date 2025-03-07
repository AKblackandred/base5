#include <limits.h>
#include <math.h>
#include "gtest/gtest.h"

#include "TinyXMLPrototypeTestHarness.h"
#include "TinyXMLPrototype.hpp"

#include <iostream>
#include <fstream>
#include <thread>

/* Reference: http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html */

TinyXMLPrototypeTestHarness::TinyXMLPrototypeTestHarness()
{
  txp = nullptr;
}

TinyXMLPrototypeTestHarness::~TinyXMLPrototypeTestHarness()
{
  txp.reset();
}

void TinyXMLPrototypeTestHarness::SetUp()
{
    this->txp.reset(new TinyXMLPrototype());
}

void TinyXMLPrototypeTestHarness::TearDown()
{
    this->txp.reset();
    this->txp = nullptr;
}

TEST_F(TinyXMLPrototypeTestHarness,constructor_noArgs)
{
    // Check defaults are set
    // Check defaults
    EXPECT_STREQ(txp->getFilename().c_str(), "not set");
}

TEST_F(TinyXMLPrototypeTestHarness,constructor_args)
{
  std::string testFilename = "test_file_name.scene";

  //Check second constructor
  this->txp.reset();
  this->txp = nullptr;

  // Create with overloaded constructor.
  this->txp.reset(new TinyXMLPrototype(testFilename));

  // Check defaults
  EXPECT_STREQ(txp->getFilename().c_str(), testFilename.c_str());

}

TEST_F(TinyXMLPrototypeTestHarness,setfilename_test)
{
  // filename
  std::string testFilename = "test_file_name.scene";

  // set the value
  this->txp->setFilename(testFilename);

  // check it's set  
  EXPECT_STREQ(txp->getFilename().c_str(), testFilename.c_str());

}

TEST_F(TinyXMLPrototypeTestHarness, openFile_test ) {

  std::string testFilename = "testfiles/dream.xml";

  // set the value
  this->txp->setFilename(testFilename);

  // test open file
  bool result = this->txp->testFileLoad();

  EXPECT_EQ(result, true);

}

TEST_F(TinyXMLPrototypeTestHarness, readTag_test ) {

  std::string testFilename = "testfiles/dream.xml";

  // set the value
  this->txp->setFilename(testFilename);

  // test open file
  bool result = this->txp->testTagRead();

  EXPECT_EQ(result, true);

}

TEST_F(TinyXMLPrototypeTestHarness, readAttribute_test ) {

  std::string testFilename = "testfiles/extendedTest.scene";

  // set the value
  this->txp->setFilename(testFilename);

  // test open file
  bool result = this->txp->testAttributeRead();

  EXPECT_EQ(result, true);

}

TEST_F(TinyXMLPrototypeTestHarness, readFloatAttribute_test ) {

  std::string testFilename = "testfiles/extendedTest.scene";

  // set the value
  this->txp->setFilename(testFilename);

  // test open file
  bool result = this->txp->testAttributeRead2();

  EXPECT_EQ(result, true);

}
