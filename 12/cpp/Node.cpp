#include <cstdlib>
#include <climits>

#include "Node.hpp"

using namespace std;

Node * const Node::NIL = new Node(0, NULL);

Node::Node(int i, Node *n) {
	setItem(i);
	setNext(n);
}

int Node::getItem() {
  return item;
}

Node *Node::getNext() {
  return next;
}

void Node::setItem(int i) {
	item = i;
}

void Node::setNext(Node *n) {
	next = n;
}

int Node::nthItem(unsigned int i) {
	unsigned int x = 0;
	Node * n =this;
	while (x < i) {
		if (n->getNext() == NULL)
			return 0;
		n =n->getNext();
	}
  return n->getItem();
}

Node *Node::nthNext(unsigned int i) {
	unsigned int x = 0;
	Node * n = this;
	while (x < i) {
		if (n->getNext() == NULL)
			return NULL;
		n = n->getNext();
	}
	return n;
}

unsigned int Node::length() {
	unsigned int length;
	Node * n = this;
	while (n->getNext()!=NULL) {
		n = n->getNext();
	}
  return length;
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
