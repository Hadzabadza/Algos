#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class ReverseNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ReverseNodeTest);
  CPPUNIT_TEST(testReverseOfNIL);
  CPPUNIT_TEST(testReverse1);
  CPPUNIT_TEST(testReverse2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testReverseOfNIL();
  void testReverse1();
  void testReverse2();
};

void ReverseNodeTest::testReverseOfNIL() {
  Node *n = Node::NIL->reverse(1);
  CPPUNIT_ASSERT(n == Node::NIL);
  n = Node::NIL->reverse(0);
  CPPUNIT_ASSERT(n == Node::NIL);  
}

void ReverseNodeTest::testReverse1() {
  Node *n = new Node(1, Node::NIL);
  Node *r = n->reverse(0);
  CPPUNIT_ASSERT(r != n);
  CPPUNIT_ASSERT(r->length() == 1);
  CPPUNIT_ASSERT(r->getItem() == 1);
  CPPUNIT_ASSERT(r->getNext() == Node::NIL);
  /* we're going to ignore memory leaks from ->reverse() for now */
  r = n->reverse(1);
  CPPUNIT_ASSERT(r->length() == 1);
  CPPUNIT_ASSERT(r == Node::NIL);
  delete n;
}

void ReverseNodeTest::testReverse2() {
  Node *n = new Node(1, Node::NIL);
  Node *nn = new Node(2, n);
  Node *r = n->reverse();
  CPPUNIT_ASSERT(r != n);
  CPPUNIT_ASSERT(r->length() == 2);
  CPPUNIT_ASSERT(r->getItem() == 1);
  CPPUNIT_ASSERT(r->getNext()->getItem() == 2);
  CPPUNIT_ASSERT(r->getNext()->getNext() == Node::NIL);
  /* again, ignoring memory leaks from ->reverse() */
  delete n, nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(ReverseNodeTest, "Reverse");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Reverse");
