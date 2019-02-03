output: main.o Element.o SparseVector.o SparseMatrix.o
	g++ -std=c++11 main.o Element.o SparseVector.o SparseMatrix.o -o exe
main : main.cpp
	g++ -std=c++11 -c main.cpp
Element.o: Element.cpp
	g++ -std=c++11 -c Element.cpp
SparseVector.o: SparseVector.cpp
	g++ -std=c++11 -c SparseVector.cpp
SparseMatrix.o : SparseMatrix.cpp
	g++ -std=c++11 -c SparseMatrix.cpp

clean:
	rm *.o exe
