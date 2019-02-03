//
// Created by mustafa paslı on 23.04.2018.
//

#include "Output.h"

bool Output::calculate() {

    if (outputInput != NULL) {
        outputValue = outputInput->calculate();
        return outputValue;
    }
    return outputValue;
}

void Output::pointInp1(Gate *inp) {
    outputInput = inp;
}

Output::Output(bool state, string name) : outputValue(state) {

    outputInput = NULL;
    setInput1(name);
}

Output::~Output() {

    delete outputInput;
}

void Output::setOutputValue(bool outputValue) {
    Output::outputValue = outputValue;
}
