#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
  Node(int, Node *);
  Node(int);
  static Node * const NIL;
  int item;
  Node * next;

  Node *getNext();
  int getItem();
  void setItem(int);
  void setNext(Node *);

  int nthItem(unsigned int);
  Node *nthNext(unsigned int);
  
  unsigned int length();
  Node *remove(int i);
  Node *reverse();
  void print();
  int sum();
  int max();
  int subMax(int max);
  Node * append(Node * with);
  void subAppend(Node * with);
  Node * merge(Node * with);
  Node * operator++();
  bool isCyclic();
};

#endif
