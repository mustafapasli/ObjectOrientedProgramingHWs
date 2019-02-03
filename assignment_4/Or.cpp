//
// Created by mustafa paslı on 23.04.2018.
//

#include "Or.h"

Or::Or(string &inputName1, string &inputName2, string &outputName) {

    orInput1 = NULL;
    orInput2 = NULL;

    calculation = false;

    setOutput1(outputName);
    setInput1(inputName1);
    setInput2(inputName2);
}

void Or::pointInp1(Gate *inp) {
    orInput1 = inp;
}

void Or::pointInp2(Gate *inp) {
    orInput2 = inp;
}

bool Or::calculate() {

    if (orInput1 != NULL && orInput2 != NULL) {
        calculation = orInput1->calculate() | orInput2->calculate();
    }
    return calculation;
}

Or::~Or() {

    delete orInput2;
    delete orInput1;

}
