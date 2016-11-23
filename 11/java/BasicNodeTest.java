import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.runner.JUnitCore;
//import barrypitman.junitXmlFormatter.AntXmlRunListener;

public class BasicNodeTest {
    @Test
    public void testConstructor() {
        Node n = new Node(0, Node.NIL);
        assertNotEquals(null, n);
        assertEquals(0, n.getItem());
        assertEquals(Node.NIL, n.getNext());
        Node nn = new Node(104, n);
        assertNotEquals(null, nn);
        assertEquals(104, nn.getItem());
        assertEquals(n, nn.getNext());
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
        // AntXmlRunListener listener = new AntXmlRunListener();
        // listener.setOutputStream(System.out);
        // core.addListener(listener);
        core.run(BasicNodeTest.class);
    }
}
