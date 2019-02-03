//
// Created by mustafa paslı on 23.04.2018.
//

#include "FlipFlop.h"
#include <iostream>

using namespace std;

Flipflop::Flipflop(string &inputName1, string &outputName) {

    ffInput = NULL;
    formerOut = false;
    counter = 0;

    setOutput1(outputName);
    setInput1(inputName1);

}

void Flipflop::pointInp1(Gate *inp) {
    ffInput = inp;
}

bool Flipflop::calculate() {

    if (ffInput != NULL) {

        if(counter == 0) { // if counter different from zero return former out else calculate return value

            counter = 1;

            if (ffInput->calculate() && formerOut) {
                formerOut = false;
                return false;
            }
            if (ffInput->calculate() && !formerOut) {
                formerOut = true;
                return true;
            }
            if (!ffInput->calculate() && !formerOut) {
                formerOut = false;
                return false;
            }
            if (!ffInput->calculate() && formerOut) {
                formerOut = true;
                return true;
            }

        }

    }
    return formerOut;
}

void Flipflop::counterReset() {
    counter = 0;
}

Flipflop::~Flipflop() {

    delete ffInput;

}
