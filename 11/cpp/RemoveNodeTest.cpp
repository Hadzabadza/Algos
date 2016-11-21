#include <cppunit/extensions/HelperMacros.h>

#include "Node.hpp"

class RemoveNodeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(RemoveNodeTest);
  CPPUNIT_TEST(testRemoveOfNIL);
  CPPUNIT_TEST(testRemove1);
  CPPUNIT_TEST(testRemove2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() { };
  void tearDown() { };

  void testRemoveOfNIL();
  void testRemove1();
  void testRemove2();
};

void RemoveNodeTest::testRemoveOfNIL() {
  Node *n = Node::NIL->remove(1);
  CPPUNIT_ASSERT(n == Node::NIL);
  n = Node::NIL->remove(0);
  CPPUNIT_ASSERT(n == Node::NIL);  
}

void RemoveNodeTest::testRemove1() {
  Node *n = new Node(1, Node::NIL);
  Node *r = n->remove(0);
  CPPUNIT_ASSERT(r != n);
  CPPUNIT_ASSERT(r->length() == 1);
  CPPUNIT_ASSERT(r->getItem() == 1);
  CPPUNIT_ASSERT(r->getNext() == Node::NIL);
  /* we're going to ignore memory leaks from ->remove() for now */
  r = n->remove(1);
  CPPUNIT_ASSERT(r->length() == 0);
  CPPUNIT_ASSERT(r == Node::NIL);
  delete n;
}

void RemoveNodeTest::testRemove2() {
  Node *n = new Node(1, Node::NIL);
  Node *nn = new Node(2, n);
  Node *r = n->remove(0);
  CPPUNIT_ASSERT(r != n);
  CPPUNIT_ASSERT(r->length() == 2);
  CPPUNIT_ASSERT(r->getItem() == 2);
  CPPUNIT_ASSERT(r->getNext()->getItem() == 1);
  CPPUNIT_ASSERT(r->getNext()->getNext() == Node::NIL);
  /* again, ignoring memory leaks from ->remove() */
  r = n->remove(1);
  CPPUNIT_ASSERT(r != n);
  CPPUNIT_ASSERT(r->length() == 1);
  CPPUNIT_ASSERT(r->getItem() == 2);
  CPPUNIT_ASSERT(r->getNext() == Node::NIL);
  
  delete n, nn;
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(RemoveNodeTest, "Remove");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Remove");
