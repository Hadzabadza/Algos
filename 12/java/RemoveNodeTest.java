import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class RemoveNodeTest {
    @Test
    public void testRemoveOfNIL() {
        Node n = Node.NIL.remove(1);
        assertEquals(Node.NIL, n);
        n = Node.NIL.remove(0);
        assertEquals(Node.NIL, n);        
    }
    @Test
    public void testRemove1() {
        Node n = new Node(1, Node.NIL);
        Node r = n.remove(0);
        assertNotEquals(n, r);
        assertEquals(1, r.length());
        assertEquals(1, r.getItem());
        assertEquals(Node.NIL, r.getNext());
        r = n.remove(1);
        assertEquals(0, r.length());
        assertEquals(Node.NIL, r);
    }
    @Test
    public void testRemove2() {
        Node n = new Node(1, Node.NIL);
        Node nn = new Node(2, n);
        Node r = nn.remove(0);
        assertNotEquals(nn, r);
        assertEquals(2, r.length());
        assertEquals(2, r.getItem());
        assertNotEquals(n, r.getNext());
        assertEquals(1, r.getNext().getItem());
        assertEquals(Node.NIL, r.getNext().getNext());
        r = nn.remove(1);
        assertNotEquals(nn, r);
        assertEquals(1, r.length());
        assertEquals(2, r.getItem());
        assertEquals(Node.NIL, r.getNext());
    }
}
