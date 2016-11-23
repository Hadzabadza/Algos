class Node {
    public Node(Object o, Node n) { }
    public static final Node NIL = new Node(Node.NIL, Node.NIL);

    public Object getItem() {
        return this;
    }
    public Node getNext() {
        return this;
    }
    public void setItem() {
    }
    public void setNext() {
    }

    // no such thing as `unsigned' in Java
    public int length() {
        return -1;
    }
    public Node remove(Object o) {
        return this;
    }
    public Node reverse() {
        return this;
    }
}
