#include <cstdlib>
#include <climits>

#include "Node.hpp"

using namespace std;

Node * const Node::NIL = new Node(0, NULL);

Node::Node(int i, Node *n) {
}

int Node::getItem() {
  return 0;
}

Node *Node::getNext() {
  return NULL;
}

void Node::setItem(int i) {
}

void Node::setNext(Node *n) {
}

int Node::nthItem(unsigned int i) {
  return 0;
}

Node *Node::nthNext(unsigned int i) {
  return NULL;
}

unsigned int Node::length() {
  return UINT_MAX;
}

Node *Node::remove(int i) {
  return NULL;
}

Node *Node::reverse() {
  return NULL;
}

/*
 * Local Variables:
 * compile-command: "make -k Node && ./Node Basic"
 * End:
 */
