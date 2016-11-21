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
  return this;
}

void Node::setItem(int i) {
}

void Node::setNext(Node *n) {
}

unsigned int Node::length() {
  return UINT_MAX;
}

Node *Node::remove(int i) {
  return this;
}

Node *Node::reverse() {
  return this;
}

/*
 * Local Variables:
 * compile-command: "make -k Node && ./Node Basic"
 * End:
 */
