#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class BasicNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BasicNodeTest);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testGetItem);
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp() { };
  void tearDown() { };

  void testConstructor();
  void testGetItem();
};

void BasicNodeTest::testConstructor() {
  Node *n = new Node(0, Node::NIL);
  CPPUNIT_ASSERT(n != NULL);
  CPPUNIT_ASSERT(n->getItem() == 0);
  CPPUNIT_ASSERT(n->getNext() == Node::NIL);
  Node *nn = new Node(104, n);
  CPPUNIT_ASSERT(nn != NULL);
  CPPUNIT_ASSERT(nn->getItem() == 104);
  CPPUNIT_ASSERT(nn->getNext() == n);
  delete n, nn;
}

#include <cstdlib>

void BasicNodeTest::testGetItem() {
  for (int k = 0; k < 100; k++) {
    int i = rand();
    Node *n = new Node(i, Node::NIL);
    CPPUNIT_ASSERT(n->getItem() == i);
  }
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BasicNodeTest, "Basic");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Basic");
