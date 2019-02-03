output: main.o Book.o Catalog.o Movie.o Music.o
	g++ -std=c++11 main.o Book.o Catalog.o Movie.o Music.o  -o exe
main : main.cpp
	g++ -std=c++11 -c main.cpp
Book.o: Book.cpp
	g++ -std=c++11 -c Book.cpp
Catalog.o : Catalog.cpp
	g++ -std=c++11 -c Catalog.cpp
Movie.o: Movie.cpp
	g++ -std=c++11 -c Movie.cpp
Music.o: Music.cpp
	g++ -std=c++11 -c Music.cpp
clean:
	rm *.o exe output.txt
