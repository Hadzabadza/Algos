#include <cstdlib>
#include <climits>
#include "Node.hpp"

Node * const Node::NIL = new Node(0, NULL);

Node::Node(int i, Node *n) {
	setItem(i);
	setNext(n);
}

Node::Node(int i) {
	setItem(i);
	setNext(NIL);
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
	Node * n = this;
	while (i>0) {
		if (n == NIL) return 0;
		n = n->getNext();
		i--;
	}
	return n->getItem();
}

Node *Node::nthNext(unsigned int i) {
	Node * n = this;
	while (i > 0) {
		i--;
		if (n == NIL) return n;
		n = n->getNext();
	}
	return n;
}

unsigned int Node::length() {
	unsigned int length = 0;
	Node * n = this;
	while (n != NIL) {
		n = n->getNext();
		length++;
	}
	return length;
}

Node *Node::remove(int i) {
	unsigned int x = i;
	if (this == NIL)
	{
		return NIL;
	}
	else
	{
		if (x == 0) {
			Node * n = this->getNext();
			this->setNext(NIL);
			return n;
		}
		else
		{
			unsigned int length = this->length();
			if (i >= length) {
				return this;
			}
			Node * n = this;
			Node * prev = n;
			if (i == length - 1) {
				while (x > 1) {
					n = n->getNext();
					x--;
				}
				n->setNext(NIL);
				return this;
			}
			else {
				while (x > 0) {
					prev = n;
					n = n->getNext();
					x--;
				}
				prev->setNext(n->getNext());
				n->setNext(NIL);
				return this;
			}
		}
	}
}

Node *Node::reverse() {
	unsigned int x = this->length();
	std::vector<Node*> miniStack;
	Node * n = this;
	while (x > 0) {
		miniStack.push_back(n);
		x--;
		n = n->getNext();
	}
	for (int i = miniStack.size() - 1; i > 0; i--)
		miniStack[i]->setNext(miniStack[i - 1]);
	if (miniStack[0] != NIL)
	{
		miniStack[0]->setNext(NIL);
		return miniStack[miniStack.size() - 1];
	}
	else
		return NIL;
}

void Node::print() {
	if (this != NIL)
	{
		cout << item << ' ';
		next->print();
	}
	else
		cout << "-X" << endl;
}

int Node::sum() {
	if (this != NIL)
		return getItem() + getNext()->sum();
	else
		return 0;
}

int Node::max() {
	if (this != NIL)
		return getNext()->subMax(getItem());
	else
		return 0;
}

int Node::subMax(int max)
{
	if (this != NIL)
	{
		if (max < getItem())
			return getNext()->subMax(getItem());
		else
			return getNext()->subMax(max);
	}
	else
		return max;
}

Node * Node::append(Node * with)
{
	if (this != NIL)
	{
		if (getNext() != NIL)
			getNext()->subAppend(with);
		else
			setNext(with);
		return this;
	}
	else
		return with;
}
void Node::subAppend(Node * with)
{
	if (getNext() != NIL)
		getNext()->subAppend(with);
	else
		setNext(with);
}

Node * Node::merge(Node * with) {
	Node * n1, *n2, *n3;
	bool resolved = 0;
	n1 = this;
	n2 = with;
	if (n2->getItem() > n1->getItem())
		n3 = n1;
	else
		n3 = n2;
	while (1)
	{
		if (n1 == NIL)
		{
			n1->append(n2);
			return n3;
		}
		if (n2 == NIL)
		{
			n2->append(n1);
			return n3;
		}
		if (n2->getItem() > n1->getItem())
		{
			Node * n = n1->getNext();
			n1->setNext(n2);
			n1 = n;
		}
		else
		{
			Node * n = n2->getNext();
			n2->setNext(n1);
			n2 = n;
		}
	}
	return NIL;
}

//TODO: Fix this

Node * Node::operator ++(){
	if (this != NIL) return this->getNext();
	else
		return this;
}

bool Node::isCyclic() {
	Node * hare = this;
	if (hare == Node::NIL) return false;
	Node * tortoise = hare;
	int steps = 0;
	int cycLength = 0;
	bool resolved = false;
	while (!resolved) {
		if (hare->getNext()==Node::NIL||hare->getNext()->getNext()==Node::NIL)
		{
			return false;
		}
		else
		{
			hare = hare->getNext()->getNext();
			tortoise = tortoise->getNext();
			steps++;
			if (hare == tortoise) resolved = true;
		}
	}
	cycLength++;
	hare = hare->getNext()->getNext();
	tortoise = tortoise->getNext();
	while (hare != tortoise)
	{
		cycLength++;
		hare = hare->getNext()->getNext();
		tortoise = tortoise->getNext();
	}
	cout << steps << " " << cycLength << endl;
	return resolved;
}

/*
 * Local Variables:
 * compile-command: "make -k Node && ./Node Basic"
 * End:
 */