NodeTest: Node.o NodeTest.o BasicNodeTest.o LengthNodeTest.o RemoveNodeTest.o ReverseNodeTest.o
	g++ -lcppunit -o $@ $^

test: NodeTest
	./NodeTest

all: NodeTest

.PHONY: test all
