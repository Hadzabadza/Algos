all: Node.class BasicNodeTest.class LengthNodeTest.class RemoveNodeTest.class ReverseNodeTest.class

%.class: %.java
	javac -cp .:/usr/share/java/junit4.jar $^

test: all
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore BasicNodeTest LengthNodeTest RemoveNodeTest ReverseNodeTest

test.xml: all
	-java -cp .:/usr/share/java/junit4.jar:/home/csr21/src/goldsmiths/JUnitXmlFormatter/target/JUnitXmlFormatter-1.0.jar -Dorg.schmant.task.junit4.target=test.xml uk.ac.gold.doc.junitXmlFormatter.Runner BasicNodeTest LengthNodeTest RemoveNodeTest ReverseNodeTest

.PHONY: test all
