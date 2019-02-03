output: main.o BaseFile.o Directory.o File.o FileManager.o 
	g++ -std=c++11 main.o BaseFile.o Directory.o File.o FileManager.o  -o exe
main : main.cpp
	g++ -std=c++11 -c main.cpp
BaseFile.o: BaseFile.cpp
	g++ -std=c++11 -c BaseFile.cpp
Directory.o : Directory.cpp
	g++ -std=c++11 -c Directory.cpp
File.o: File.cpp
	g++ -std=c++11 -c File.cpp
FileManager.o: FileManager.cpp
	g++ -std=c++11 -c FileManager.cpp
clean:
	rm *.o exe output.txt
