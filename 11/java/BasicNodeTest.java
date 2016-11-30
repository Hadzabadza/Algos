import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class BasicNodeTest {
    @Test
    public void testConstructor() {
        Node n = new Node(0, Node.NIL);
        assertNotEquals("The Node constructor must never return null", null, n);
        assertEquals("The Node constructor must treat its first argument as the item (or getItem() isn't working yet)", 0, n.getItem());
        assertEquals("The Node constructor must treat its second argument as the next node (or getNext() isn't working yet)", Node.NIL, n.getNext());
        Node nn = new Node(104, n);
        assertNotEquals("The Node constructor must never return null", null, nn);
        assertEquals("The Node constructor must treat its first argument as the item (or getItem() isn't working yet); something might be defaulting to 0", 104, nn.getItem());
        assertEquals("The Node constructor must treat its second argument as the next node (or getNext() isn't working yet); something might be defaulting to Node.NIL", n, nn.getNext());
    }
    @Test
    public void testGetItem() {
        Random r = new Random();
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(Integer.MAX_VALUE);
            Node n = new Node(i, Node.NIL);
            assertEquals(i, n.getItem());
        }
    }

    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        // no listeners, no output
        Result result = core.run(BasicNodeTest.class);
        System.exit(result.wasSuccessful() ? 0 : 1);
    }
}
