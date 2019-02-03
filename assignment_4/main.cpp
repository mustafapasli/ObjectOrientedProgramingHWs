#include <iostream>
#include "LogicSimulator.h"

using namespace std;

int main() {

    LogicSimulator circuit; //logic circuit object

    circuit.readInputOutputFromFile(); //reads input and output line from line
    circuit.readGatesFromFile();  // reads and or not vs. gates from file
    circuit.connectGates(); // points gates each other
    circuit.calculate(); // calculates output results and print screen

    return 0;
}