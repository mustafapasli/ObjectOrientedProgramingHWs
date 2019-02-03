//
// Created by mustafa paslı on 23.04.2018.
//

#include "And.h"

And::And(string &inputName1, string &inputName2, string &outputName) {

    andInput1 = NULL;
    andInput2 = NULL;

    calculation = false;

    setOutput1(outputName);
    setInput1(inputName1);
    setInput2(inputName2);
}

bool And::calculate() {
    if (andInput1 != NULL && andInput2 != NULL) {
        andInput1->calculate();
        andInput2->calculate();
        calculation = andInput1->calculate() & andInput2->calculate();
    }

    return calculation;
}

void And::pointInp2(Gate *inp) {
    andInput2 = inp;
}

void And::pointInp1(Gate *inp) {
    andInput1 = inp;
}

And::~And() {

    delete andInput1;
    delete andInput2;
}
