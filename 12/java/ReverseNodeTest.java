import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class ReverseNodeTest {
    @Test
    public void testReverseOfNIL() {
        Node n = Node.NIL.reverse();
        assertEquals(Node.NIL, n);
    }
    @Test
    public void testReverse1() {
        Node n = new Node(1, Node.NIL);
        Node r = n.reverse();
        assertNotEquals(n, r);
        assertEquals(1, r.length());
        assertEquals(1, r.getItem());
        assertEquals(Node.NIL, r.getNext());
    }
    @Test
    public void testReverse2() {
        Node n = new Node(1, Node.NIL);
        Node nn = new Node(2, n);
        Node r = nn.reverse();
        assertNotEquals(nn, r);
        assertEquals(2, r.length());
        assertEquals(1, r.getItem());
        assertNotEquals(n, r.getNext());
        assertEquals(2, r.getNext().getItem());
        assertEquals(Node.NIL, r.getNext().getNext());
    }
}
