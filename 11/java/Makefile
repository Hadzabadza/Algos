include ../../java.mk

TESTCLASSFILES = BasicNodeTest.class
CLASSFILES = Node.class $(TESTCLASSFILES)

all: $(CLASSFILES)

clean:
	-rm -f $(CLASSFILES) test.xml

%.class: %.java
	$(JAVAC) $(CLASSPATH) $^

test: all
	(((($(JAVA) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

test.xml: all
	-java -cp .:/usr/share/java/junit4.jar:/home/csr21/src/goldsmiths/JUnitXmlFormatter/target/JUnitXmlFormatter-1.0.jar -Dorg.schmant.task.junit4.target=test.xml uk.ac.gold.doc.junitXmlFormatter.Runner $(subst .class,,$(TESTCLASSFILES))

.PHONY: test all clean
