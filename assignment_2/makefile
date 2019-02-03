output: main.o Card.o Grid.o Player.o Tsuro.o
	g++ -std=c++11 main.o Card.o Grid.o Player.o Tsuro.o -o exe
main : main.cpp
	g++ -std=c++11 -c main.cpp
Card.o: Card.cpp
	g++ -std=c++11 -c Card.cpp
Grid.o: Grid.cpp
	g++ -std=c++11 -c Grid.cpp
Player.o : Player.cpp
	g++ -std=c++11 -c Player.cpp
Tsuro.o : Tsuro.cpp
	g++ -std=c++11 -c Tsuro.cpp

clean:
	rm *.o exe
