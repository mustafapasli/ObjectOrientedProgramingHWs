output: main.o And.o Decoder.o FlipFlop.o Gate.o Input.o LogicSimulator.o Not.o Or.o Output.o
	g++ -std=c++11 main.o And.o Decoder.o FlipFlop.o Gate.o Input.o LogicSimulator.o Not.o Or.o Output.o -o exe
main : main.cpp
	g++ -std=c++11 -c main.cpp
And.o: And.cpp
	g++ -std=c++11 -c And.cpp
Gate.o: Gate.cpp
	g++ -std=c++11 -c Gate.cpp
Input.o : Input.cpp
	g++ -std=c++11 -c Input.cpp
Not.o: Not.cpp
	g++ -std=c++11 -c Not.cpp
Output.o : Output.cpp
	g++ -std=c++11 -c Output.cpp
Decoder.o : Decoder.cpp
	g++ -std=c++11 -c Decoder.cpp
FlipFlop.o: FlipFlop.cpp
	g++ -std=c++11 -c FlipFlop.cpp
LogicSimilator.o: LogicSimilator.cpp
	g++ -std=c++11 -c LogicSimilator.cpp
clean:
	rm *.o exe
