all: Node.class BasicNodeTest.class LengthNodeTest.class RemoveNodeTest.class ReverseNodeTest.class

%.class: %.java
	javac -cp .:/usr/share/java/junit4.jar $^

test: all
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore BasicNodeTest LengthNodeTest RemoveNodeTest ReverseNodeTest

