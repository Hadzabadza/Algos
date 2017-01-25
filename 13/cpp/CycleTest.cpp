#include <cmath>
#include <chrono>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Node.hpp"
#include "CycleInfo.hpp"

class CycleTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(CycleTest);
  CPPUNIT_TEST(testNoncyclicDetection);
  CPPUNIT_TEST(testSmallCyclicDetection);
  //CPPUNIT_TEST(testRandomCyclicDetection);
  //CPPUNIT_TEST(testNoncyclicInfo);
  //CPPUNIT_TEST(testCyclicAtStartInfo);
  //CPPUNIT_TEST(testRandomCyclicInfo);
  CPPUNIT_TEST_SUITE_END();
public:
  void testNoncyclicDetection();
  void testSmallCyclicDetection();
  //void testRandomCyclicDetection();
  //void testNoncyclicInfo();
  //void testCyclicAtStartInfo();
  //void testRandomCyclicInfo();
};

void CycleTest::testNoncyclicDetection() {
  CPPUNIT_ASSERT_MESSAGE("Node::NIL is not cyclic by definition", !isCyclic(Node::NIL));
  Node *n = new Node(1, Node::NIL);
  CPPUNIT_ASSERT_MESSAGE("A one-element list is not cyclic", !isCyclic(n));
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT_MESSAGE("A two-element list is not cyclic", !isCyclic(nn));
  delete n;
  delete nn;
}

void CycleTest::testSmallCyclicDetection() {
  Node *n = new Node(1, n);
  CPPUNIT_ASSERT_MESSAGE("A one-element cyclic list should be detected as cyclic", isCyclic(n));
  Node *nn = new Node(2, n);
  CPPUNIT_ASSERT_MESSAGE("A two-element list with a cycle at the end should be detected as cyclic", isCyclic(nn));
  n->setNext(nn);
  CPPUNIT_ASSERT_MESSAGE("A two-element list cycling back to the start should be detected as cyclic", isCyclic(nn));
  CPPUNIT_ASSERT_MESSAGE("A two-element list cycling back to the start should be detected as cyclic wherever you start", isCyclic(n));
}

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CycleTest, "Cycle");
CPPUNIT_REGISTRY_ADD_TO_DEFAULT("Cycle");

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cerr << "Usage: " << argv[0] << " [suitename]" << std::endl;
    return 1;
  }
  CppUnit::Test *test;
  CppUnit::TextUi::TestRunner runner;
  if (argc == 2)
    test = CppUnit::TestFactoryRegistry::getRegistry(argv[1]).makeTest();
  else
    test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  runner.addTest(test);
  runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

  bool wasSuccessful = runner.run();
  return wasSuccessful ? 0 : 1;
}
