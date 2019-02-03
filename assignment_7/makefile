JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:  
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    DrawSkylinePanel.java \
    Rectangle.java \
    Skyline.java \
    Point.java \
    Main.java \

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class