class Node {
public:
  Node(int, Node *);
  static Node * const NIL;

  Node *getNext();
  int getItem();
  void setItem(int);
  void setNext(Node *);

  unsigned int length();
  Node *remove(int i);
  Node *reverse();
};
