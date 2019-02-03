//
// Created by mustafa paslı on 23.04.2018.
//

#include "LogicSimulator.h"
#include <fstream>

LogicSimulator::LogicSimulator() {

    //resetting variables and pointers

    numberOfInput = 0;
    numberOfOutput = 0;

    numberOfAndGate = 0;
    numberOfOrGate = 0;
    numberOfNotGate = 0;
    numberOfFFGate = 0;
    numberOfDecGate = 0;

    numberOfLineCircuit = 0;

    outPArr = NULL;
    inPArr = NULL;

    andPArr = NULL;
    orPArr = NULL;
    notPArr = NULL;
    flipflopPArr = NULL;
    decoderPArr = NULL;

}

void LogicSimulator::readInputOutputFromFile() {

    int spaceNumber = 0; // keep space number in line

    ifstream circuitFile;

    circuitFile.open("circuit.txt"); // opening circuit file

    string inputName;
    string line;

    while (getline(circuitFile, line)) { //gets line from file line by line

        size_t found; // index of finding word

        found = line.find("OUTPUT");
        if (found != string::npos) {
            for (int i = 0; i < line.length(); ++i) { // finding space number for number of outputs
                if (line[i] == ' ') {
                    spaceNumber++;
                }
            }

            numberOfOutput = spaceNumber;

            int a = 7; // index of "OUTPUT" words last latter in the line

            outPArr = new Output *[numberOfOutput]; // keep memory for outputs

            for (int j = 0; j < spaceNumber; ++j) { // parsing line by output name
                int i;
                for (i = a; line[i] != ' ' && i < line.length(); ++i) {
                    inputName.push_back(line[i]);
                }
                a = i + 1;

                outPArr[j] = new Output(false, inputName);
                inputName.erase();
            }

            spaceNumber = 0;
        }

        found = line.find("INPUT");
        if (found != string::npos) {
            for (int i = 0; i < line.length(); ++i) { // finding space number for number of inputs
                if (line[i] == ' ') {
                    spaceNumber++;
                }
            }

            numberOfInput = spaceNumber;

            int a = 6;// index of "INPUT" words last latter in the line

            inPArr = new Input *[spaceNumber]; // keep memory for inputs
            for (int j = 0; j < spaceNumber; ++j) { // parsing line by input name

                int i;
                for (i = a; line[i] != ' ' && i < line.length(); ++i) {
                    inputName.push_back(line[i]);
                }
                a = i + 1;

                inPArr[j] = new Input(inputName);
                inputName.erase();
            }

            spaceNumber = 0;
        }

        found = line.find("AND"); // finding number of AND gates
        if (found != string::npos) {
            numberOfAndGate++;

        }

        found = line.find("OR");// finding number of OR gates
        if (found != string::npos) {
            numberOfOrGate++;

        }

        found = line.find("NOT");// finding number of NOT gates
        if (found != string::npos) {
            numberOfNotGate++;

        }

        found = line.find("FLIPFLOP");// finding number of FLIPFLOP gates
        if (found != string::npos) {
            numberOfFFGate++;

        }

        found = line.find("DECODER");// finding number of DECODER gates
        if (found != string::npos) {
            numberOfDecGate++;

        }

        numberOfLineCircuit++; // increasing number of line

    }

    circuitFile.close(); // closing file

}

void LogicSimulator::readGatesFromFile() {

    ifstream circuitFile;
    circuitFile.open("circuit.txt"); // opening file

    // keeping memory for gates

    if (numberOfAndGate > 0)
        andPArr = new And *[numberOfAndGate];
    if (numberOfOrGate > 0)
        orPArr = new Or *[numberOfOrGate];
    if (numberOfNotGate > 0)
        notPArr = new Not *[numberOfNotGate];
    if (numberOfFFGate > 0)
        flipflopPArr = new Flipflop *[numberOfFFGate];
    if (numberOfDecGate > 0)
        decoderPArr = new Decoder *[numberOfDecGate];

    // keeps gates counter for index of pointer array
    int andCounter = 0;
    int orCounter = 0;
    int notCounter = 0;
    int ffCounter = 0;
    int decCounter = 0;

    // keeps parsing line components
    string inp1;
    string inp2;
    string outp1;
    string outp2;
    string outp3;
    string outp4;

    string line;

    while (getline(circuitFile, line)) {
        size_t found;

        found = line.find("AND");
        if (found != string::npos) {

            int a = 0; // word counter after "AND"
            for (int i = 4; i < line.length(); ++i) {
                if (line[i] == ' ') { // if i. index is space increase 'a' for keeping next word
                    a++;
                } else {
                    if (a == 0) {
                        outp1.push_back(line[i]);
                    }
                    if (a == 1) {
                        inp1.push_back(line[i]);
                    }
                    if (a == 2) {
                        inp2.push_back(line[i]);
                    }
                }
            }

            andPArr[andCounter] = new And(inp1, inp2, outp1); // keep memory for and gate
            inp1.erase();
            inp2.erase();
            outp1.erase();
            andCounter++; // increase andCounter for next and gate
        }


        found = line.find("OR");
        if (found != string::npos) {

            int a = 0;// word counter after "OR"
            for (int i = 3; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    a++;
                } else {
                    if (a == 0) {
                        outp1.push_back(line[i]);
                    }
                    if (a == 1) {
                        inp1.push_back(line[i]);
                    }
                    if (a == 2) {
                        inp2.push_back(line[i]);
                    }
                }
            }

            orPArr[orCounter] = new Or(inp1, inp2, outp1); // keep memory for OR gate
            inp1.erase();
            inp2.erase();
            outp1.erase();
            orCounter++;// increase andCounter for next or gate
        }


        found = line.find("NOT");
        if (found != string::npos) {

            int a = 0;
            for (int i = 4; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    a++;
                } else {
                    if (a == 0) {
                        outp1.push_back(line[i]);
                    }
                    if (a == 1) {
                        inp1.push_back(line[i]);
                    }
                }
            }

            notPArr[notCounter] = new Not(inp1, outp1);
            inp1.erase();
            outp1.erase();
            notCounter++;
        }


        found = line.find("FLIPFLOP");
        if (found != string::npos) {

            int a = 0;// word counter after "FLIPFLOP"
            for (int i = 9; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    a++;
                } else {
                    if (a == 0) {
                        outp1.push_back(line[i]);
                    }
                    if (a == 1) {
                        inp1.push_back(line[i]);
                    }
                }
            }

            flipflopPArr[ffCounter] = new Flipflop(inp1, outp1);// keep memory for FLIPFLOP gate
            inp1.erase();
            outp1.erase();
            ffCounter++;// increase andCounter for next FLIPFLOP gate
        }


        found = line.find("DECODER");
        if (found != string::npos) {

            int a = 0;// word counter after "DECODER"
            for (int i = 8; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    a++;
                } else {
                    if (a == 0) {
                        outp1.push_back(line[i]);
                    }
                    if (a == 1) {
                        outp2.push_back(line[i]);
                    }
                    if (a == 2) {
                        outp3.push_back(line[i]);
                    }
                    if (a == 3) {
                        outp4.push_back(line[i]);
                    }
                    if (a == 4) {
                        inp1.push_back(line[i]);
                    }
                    if (a == 5) {
                        inp2.push_back(line[i]);
                    }
                }
            }

            decoderPArr[decCounter] = new Decoder(outp1, outp2, outp3, outp4, inp1,
                                                  inp2);// keep memory for DECODER gate

            inp1.erase();
            inp2.erase();

            outp1.erase();
            outp2.erase();
            outp3.erase();
            outp4.erase();

            decCounter++;// increase andCounter for next DECODER gate
        }

    }

    circuitFile.close(); // closing file

}

void LogicSimulator::connectGates() {


    for (int k = 0; k < numberOfAndGate; ++k) { // pointing AND gates inputs by other gates output names
        for (int i = 0; i < numberOfInput; ++i) {
            if (andPArr[k]->getInput1() == inPArr[i]->getOutput1()) { // if the first input of AND same  inputs output
                andPArr[k]->pointInp1(inPArr[i]); // pointing
            }
            if (andPArr[k]->getInput2() == inPArr[i]->getOutput1()) { // if the second input of AND same  inputs output
                andPArr[k]->pointInp2(inPArr[i]); // pointing
            }
        }

        for (int j = 0; j < numberOfAndGate; ++j) {  // The following are the same as above.
            if (andPArr[k]->getInput1() == andPArr[j]->getOutput1()) {
                andPArr[k]->pointInp1(andPArr[j]);
            }
            if (andPArr[k]->getInput2() == andPArr[j]->getOutput1()) {
                andPArr[k]->pointInp2(andPArr[j]);
            }
        }

        for (int j = 0; j < numberOfOrGate; ++j) {
            if (andPArr[k]->getInput1() == orPArr[j]->getOutput1()) {
                andPArr[k]->pointInp1(orPArr[j]);
            }
            if (andPArr[k]->getInput2() == orPArr[j]->getOutput1()) {
                andPArr[k]->pointInp2(orPArr[j]);
            }
        }

        for (int j = 0; j < numberOfNotGate; ++j) {
            if (andPArr[k]->getInput1() == notPArr[j]->getOutput1()) {
                andPArr[k]->pointInp1(notPArr[j]);
            }
            if (andPArr[k]->getInput2() == notPArr[j]->getOutput1()) {
                andPArr[k]->pointInp2(notPArr[j]);
            }
        }


        for (int j = 0; j < numberOfFFGate; ++j) {
            if (andPArr[k]->getInput1() == flipflopPArr[j]->getOutput1()) {
                andPArr[k]->pointInp1(flipflopPArr[j]);
            }
            if (andPArr[k]->getInput2() == flipflopPArr[j]->getOutput1()) {
                andPArr[k]->pointInp2(flipflopPArr[j]);
            }
        }

        for (int j = 0; j < numberOfDecGate; ++j) {
            if (andPArr[k]->getInput1() == decoderPArr[j]->getOutput1()) {
                andPArr[k]->pointInp1(decoderPArr[j]->getOut1());
            }
            if (andPArr[k]->getInput1() == decoderPArr[j]->getOutput2()) {
                andPArr[k]->pointInp1(decoderPArr[j]->getOut2());
            }
            if (andPArr[k]->getInput1() == decoderPArr[j]->getOutput3()) {
                andPArr[k]->pointInp1(decoderPArr[j]->getOut3());
            }
            if (andPArr[k]->getInput1() == decoderPArr[j]->getOutput4()) {
                andPArr[k]->pointInp1(decoderPArr[j]->getOut4());
            }
            if (andPArr[k]->getInput2() == decoderPArr[j]->getOutput1()) {
                andPArr[k]->pointInp2(decoderPArr[j]->getOut1());
            }
            if (andPArr[k]->getInput2() == decoderPArr[j]->getOutput2()) {
                andPArr[k]->pointInp2(decoderPArr[j]->getOut2());
            }
            if (andPArr[k]->getInput2() == decoderPArr[j]->getOutput3()) {
                andPArr[k]->pointInp2(decoderPArr[j]->getOut3());
            }
            if (andPArr[k]->getInput2() == decoderPArr[j]->getOutput4()) {
                andPArr[k]->pointInp2(decoderPArr[j]->getOut4());
            }
        }
    }

    for (int k = 0; k < numberOfOrGate; ++k) { // pointing OR gates inputs by other gates output names
        for (int i = 0; i < numberOfInput; ++i) {
            if (orPArr[k]->getInput1() == inPArr[i]->getOutput1()) {
                orPArr[k]->pointInp1(inPArr[i]);
            }
            if (orPArr[k]->getInput2() == inPArr[i]->getOutput1()) {
                orPArr[k]->pointInp2(inPArr[i]);
            }
        }

        for (int j = 0; j < numberOfAndGate; ++j) {
            if (orPArr[k]->getInput1() == andPArr[j]->getOutput1()) {
                orPArr[k]->pointInp1(andPArr[j]);
            }
            if (orPArr[k]->getInput2() == andPArr[j]->getOutput1()) {
                orPArr[k]->pointInp2(andPArr[j]);
            }
        }

        for (int j = 0; j < numberOfOrGate; ++j) {
            if (orPArr[k]->getInput1() == orPArr[j]->getOutput1()) {
                orPArr[k]->pointInp1(orPArr[j]);
            }
            if (orPArr[k]->getInput2() == orPArr[j]->getOutput1()) {
                orPArr[k]->pointInp2(orPArr[j]);
            }
        }

        for (int j = 0; j < numberOfNotGate; ++j) {
            if (orPArr[k]->getInput1() == notPArr[j]->getOutput1()) {
                orPArr[k]->pointInp1(notPArr[j]);
            }
            if (orPArr[k]->getInput2() == notPArr[j]->getOutput1()) {
                orPArr[k]->pointInp2(notPArr[j]);
            }
        }


        for (int j = 0; j < numberOfFFGate; ++j) {
            if (orPArr[k]->getInput1() == flipflopPArr[j]->getOutput1()) {
                orPArr[k]->pointInp1(flipflopPArr[j]);
            }
            if (orPArr[k]->getInput2() == flipflopPArr[j]->getOutput1()) {
                orPArr[k]->pointInp2(flipflopPArr[j]);
            }
        }

        for (int j = 0; j < numberOfDecGate; ++j) {
            if (orPArr[k]->getInput1() == decoderPArr[j]->getOutput1()) {
                orPArr[k]->pointInp1(decoderPArr[j]->getOut1());
            }
            if (orPArr[k]->getInput1() == decoderPArr[j]->getOutput2()) {
                orPArr[k]->pointInp1(decoderPArr[j]->getOut2());
            }
            if (orPArr[k]->getInput1() == decoderPArr[j]->getOutput3()) {
                orPArr[k]->pointInp1(decoderPArr[j]->getOut3());
            }
            if (orPArr[k]->getInput1() == decoderPArr[j]->getOutput4()) {
                orPArr[k]->pointInp1(decoderPArr[j]->getOut4());
            }
            if (orPArr[k]->getInput2() == decoderPArr[j]->getOutput1()) {
                orPArr[k]->pointInp2(decoderPArr[j]->getOut1());
            }
            if (orPArr[k]->getInput2() == decoderPArr[j]->getOutput2()) {
                orPArr[k]->pointInp2(decoderPArr[j]->getOut2());
            }
            if (orPArr[k]->getInput2() == decoderPArr[j]->getOutput3()) {
                orPArr[k]->pointInp2(decoderPArr[j]->getOut3());
            }
            if (orPArr[k]->getInput2() == decoderPArr[j]->getOutput4()) {
                orPArr[k]->pointInp2(decoderPArr[j]->getOut4());
            }
        }
    }

    for (int k = 0; k < numberOfNotGate; ++k) { // pointing NOT gates inputs by other gates output names
        for (int i = 0; i < numberOfInput; ++i) {
            if (notPArr[k]->getInput1() == inPArr[i]->getOutput1()) {
                notPArr[k]->pointInp1(inPArr[i]);
            }
        }

        for (int j = 0; j < numberOfAndGate; ++j) {
            if (notPArr[k]->getInput1() == andPArr[j]->getOutput1()) {
                notPArr[k]->pointInp1(andPArr[j]);
            }
        }

        for (int j = 0; j < numberOfOrGate; ++j) {
            if (notPArr[k]->getInput1() == orPArr[j]->getOutput1()) {
                notPArr[k]->pointInp1(orPArr[j]);
            }
        }

        for (int j = 0; j < numberOfNotGate; ++j) {
            if (notPArr[k]->getInput1() == notPArr[j]->getOutput1()) {
                notPArr[k]->pointInp1(notPArr[j]);
            }
        }


        for (int j = 0; j < numberOfFFGate; ++j) {
            if (notPArr[k]->getInput1() == flipflopPArr[j]->getOutput1()) {
                notPArr[k]->pointInp1(flipflopPArr[j]);
            }

        }

        for (int j = 0; j < numberOfDecGate; ++j) {
            if (notPArr[k]->getInput1() == decoderPArr[j]->getOutput1()) {
                notPArr[k]->pointInp1(decoderPArr[j]->getOut1());
            }
            if (notPArr[k]->getInput1() == decoderPArr[j]->getOutput2()) {
                notPArr[k]->pointInp1(decoderPArr[j]->getOut2());
            }
            if (notPArr[k]->getInput1() == decoderPArr[j]->getOutput3()) {
                notPArr[k]->pointInp1(decoderPArr[j]->getOut3());
            }
            if (notPArr[k]->getInput1() == decoderPArr[j]->getOutput4()) {
                notPArr[k]->pointInp1(decoderPArr[j]->getOut4());
            }
        }
    }

    for (int k = 0; k < numberOfFFGate; ++k) { // pointing FLIPFLOP gates inputs by other gates output names
        for (int i = 0; i < numberOfInput; ++i) {
            if (flipflopPArr[k]->getInput1() == inPArr[i]->getOutput1()) {
                flipflopPArr[k]->pointInp1(inPArr[i]);
            }
        }

        for (int j = 0; j < numberOfAndGate; ++j) {
            if (flipflopPArr[k]->getInput1() == andPArr[j]->getOutput1()) {
                flipflopPArr[k]->pointInp1(andPArr[j]);
            }
        }

        for (int j = 0; j < numberOfOrGate; ++j) {
            if (flipflopPArr[k]->getInput1() == orPArr[j]->getOutput1()) {
                flipflopPArr[k]->pointInp1(orPArr[j]);
            }
        }

        for (int j = 0; j < numberOfNotGate; ++j) {
            if (flipflopPArr[k]->getInput1() == notPArr[j]->getOutput1()) {
                flipflopPArr[k]->pointInp1(notPArr[j]);
            }
        }


        for (int j = 0; j < numberOfFFGate; ++j) {
            if (flipflopPArr[k]->getInput1() == flipflopPArr[j]->getOutput1()) {
                flipflopPArr[k]->pointInp1(flipflopPArr[j]);
            }

        }

        for (int j = 0; j < numberOfDecGate; ++j) {
            if (flipflopPArr[k]->getInput1() == decoderPArr[j]->getOutput1()) {
                flipflopPArr[k]->pointInp1(decoderPArr[j]->getOut1());
            }
            if (flipflopPArr[k]->getInput1() == decoderPArr[j]->getOutput2()) {
                flipflopPArr[k]->pointInp1(decoderPArr[j]->getOut2());
            }
            if (flipflopPArr[k]->getInput1() == decoderPArr[j]->getOutput3()) {
                flipflopPArr[k]->pointInp1(decoderPArr[j]->getOut3());
            }
            if (flipflopPArr[k]->getInput1() == decoderPArr[j]->getOutput4()) {
                flipflopPArr[k]->pointInp1(decoderPArr[j]->getOut4());
            }
        }
    }

    for (int k = 0; k < numberOfDecGate; ++k) { // pointing DECODER gates inputs by other gates output names
        for (int i = 0; i < numberOfInput; ++i) {
            if (decoderPArr[k]->getInput1() == inPArr[i]->getOutput1()) {
                decoderPArr[k]->pointInp1(inPArr[i]);
            }
            if (decoderPArr[k]->getInput2() == inPArr[i]->getOutput1()) {
                decoderPArr[k]->pointInp2(inPArr[i]);
            }
        }

        for (int j = 0; j < numberOfAndGate; ++j) {
            if (decoderPArr[k]->getInput1() == andPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp1(andPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == andPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp2(andPArr[j]);
            }
        }

        for (int j = 0; j < numberOfOrGate; ++j) {
            if (decoderPArr[k]->getInput1() == orPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp1(orPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == orPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp2(orPArr[j]);
            }
        }

        for (int j = 0; j < numberOfNotGate; ++j) {
            if (decoderPArr[k]->getInput1() == notPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp1(notPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == notPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp2(notPArr[j]);
            }
        }


        for (int j = 0; j < numberOfFFGate; ++j) {
            if (decoderPArr[k]->getInput1() == flipflopPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp1(flipflopPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == flipflopPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp2(flipflopPArr[j]);
            }
        }

        for (int j = 0; j < numberOfDecGate; ++j) {
            if (decoderPArr[k]->getInput1() == decoderPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp1(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput1() == decoderPArr[j]->getOutput2()) {
                decoderPArr[k]->pointInp1(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput1() == decoderPArr[j]->getOutput3()) {
                decoderPArr[k]->pointInp1(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput1() == decoderPArr[j]->getOutput4()) {
                decoderPArr[k]->pointInp1(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == decoderPArr[j]->getOutput1()) {
                decoderPArr[k]->pointInp2(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == decoderPArr[j]->getOutput2()) {
                decoderPArr[k]->pointInp2(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == decoderPArr[j]->getOutput3()) {
                decoderPArr[k]->pointInp2(decoderPArr[j]);
            }
            if (decoderPArr[k]->getInput2() == decoderPArr[j]->getOutput4()) {
                decoderPArr[k]->pointInp2(decoderPArr[j]);
            }
        }


    }

    for (int k = 0; k < numberOfOutput; ++k) { // pointing OUTPUT inputs by other gates output names
        for (int i = 0; i < numberOfInput; ++i) {
            if (outPArr[k]->getInput1() == inPArr[i]->getOutput1()) {
                outPArr[k]->pointInp1(inPArr[i]);
            }
        }

        for (int j = 0; j < numberOfAndGate; ++j) {
            if (outPArr[k]->getInput1() == andPArr[j]->getOutput1()) {
                outPArr[k]->pointInp1(andPArr[j]);
            }
        }

        for (int j = 0; j < numberOfOrGate; ++j) {
            if (outPArr[k]->getInput1() == orPArr[j]->getOutput1()) {
                outPArr[k]->pointInp1(orPArr[j]);
            }
        }

        for (int j = 0; j < numberOfNotGate; ++j) {
            if (outPArr[k]->getInput1() == notPArr[j]->getOutput1()) {
                outPArr[k]->pointInp1(notPArr[j]);
            }
        }


        for (int j = 0; j < numberOfFFGate; ++j) {
            if (outPArr[k]->getInput1() == flipflopPArr[j]->getOutput1()) {
                outPArr[k]->pointInp1(flipflopPArr[j]);
            }

        }

        for (int j = 0; j < numberOfDecGate; ++j) {

            if (outPArr[k]->getInput1() == decoderPArr[j]->getOutput1()) {
                decoderPArr[j]->setOut1(outPArr[k]);
            }
            if (outPArr[k]->getInput1() == decoderPArr[j]->getOutput2()) {
                decoderPArr[j]->setOut2(outPArr[k]);
            }
            if (outPArr[k]->getInput1() == decoderPArr[j]->getOutput3()) {
                decoderPArr[j]->setOut3(outPArr[k]);
            }
            if (outPArr[k]->getInput1() == decoderPArr[j]->getOutput4()) {
                decoderPArr[j]->setOut4(outPArr[k]);

            }

        }
    }

}

void LogicSimulator::calculate() {

    ifstream inputFile;

    inputFile.open("input.txt"); // opening input file

    string line;

    while (getline(inputFile, line)) { // getting line bye line
        for (int i = 0; i < numberOfInput; ++i) { // asssigning input values to INPUTs

            if (line[i * 2] == '0')
                inPArr[i]->setInputValue(false);
            if (line[i * 2] == '1')
                inPArr[i]->setInputValue(true);
        }


        for (int l = 0; l < numberOfLineCircuit; ++l) { // calculating all gates output values
            // the input results are repeated until it is full.

            for (int j = 0; j < numberOfAndGate; ++j) {
                andPArr[j]->calculate();
            }

            for (int j = 0; j < numberOfOrGate; ++j) {
                orPArr[j]->calculate();
            }

            for (int j = 0; j < numberOfNotGate; ++j) {
                notPArr[j]->calculate();
            }

            for (int j = 0; j < numberOfDecGate; ++j) {
                decoderPArr[j]->calculate();

            }
            for (int j = 0; j < numberOfFFGate; ++j) {
                flipflopPArr[j]->calculate();
            }

        }
        for (int j = 0; j < numberOfOutput; ++j) { // calculating outputs output and print screen
            cout << outPArr[j]->calculate() << " ";
        }
        cout << endl;

        for (int j = 0; j < numberOfFFGate; ++j) { // resets flipflop gates counter to zero
            flipflopPArr[j]->counterReset();
        }

    }

}


LogicSimulator::~LogicSimulator() {

    delete[] inPArr;

    delete[] outPArr;

    delete[] andPArr;

    delete[] notPArr;

    delete[] flipflopPArr;

    delete[] decoderPArr;

    delete[] orPArr;

}
