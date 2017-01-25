#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
  Node(int, Node *);
  static Node * const NIL;

  Node *getNext();
  int getItem();
  void setItem(int);
  void setNext(Node *);

  int nthItem(unsigned int);
  Node *nthNext(unsigned int);
  
  unsigned int length();
  Node *remove(int i);
  Node *reverse();
};

#endif
