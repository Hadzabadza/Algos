import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class LengthNodeTest {
    @Test
    public void testLengthOfNIL() {
        assertEquals(0, Node.NIL.length());
    }
    @Test
    public void testLength() {
        Node n = new Node(1, Node.NIL);
        assertEquals(1, n.length());
        Node nn = new Node(2, n);
        assertEquals(2, n.length());
    }
    
    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        core.run(LengthNodeTest.class);
    }
}
