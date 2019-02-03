//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_LOGICSIMULATOR_H
#define CPP4_LOGICSIMULATOR_H

#include "Gate.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Input.h"
#include "Output.h"
#include "Decoder.h"
#include "FlipFlop.h"

class LogicSimulator {

    int numberOfInput;
    int numberOfOutput;

    int numberOfAndGate;
    int numberOfOrGate;
    int numberOfNotGate;
    int numberOfFFGate;
    int numberOfDecGate;

    int numberOfLineCircuit; // number of line in circuit file

    Output **outPArr; // output gates pointer array
    Input **inPArr; // input gates pointer array

    And **andPArr; // and gates pointer array
    Or **orPArr; // or gates pointer array
    Not **notPArr; // not gates pointer array
    Flipflop **flipflopPArr; // flipflop gates pointer array
    Decoder **decoderPArr; // decoder gates pointer array

public:

    LogicSimulator();

    void readInputOutputFromFile(); //reads input and output line from line

    void readGatesFromFile(); // reads and or not vs. gates from file

    void connectGates(); // points gates each other

    void calculate(); // calculates output results and print screen

    ~LogicSimulator();

};

#endif
