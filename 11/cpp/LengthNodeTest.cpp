#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class LengthNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LengthNodeTest);
  CPPUNIT_TEST(testLengthOfNIL);
  CPPUNIT_TEST(testLength);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testLengthOfNIL();
  void testLength();
};

void LengthNodeTest::testLengthOfNIL() {
  CPPUNIT_ASSERT(Node::NIL->length() == 0);
}

void LengthNodeTest::testLength() {
  Node *n = new Node(1, Node::NIL);
  CPPUNIT_ASSERT(n->length() == 1);
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT(n->length() == 2);
  delete n, nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(LengthNodeTest, "Length");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Length");
