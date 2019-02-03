//
// Created by mustafa paslı on 23.04.2018.
//

#include "Not.h"

Not::~Not() {
    delete notInput;
}

bool Not::calculate() {
    if (notInput != NULL) {
        return !notInput->calculate();
    }
    return false;
}

void Not::pointInp1(Gate *inp) {
    notInput = inp;
}

Not::Not(string &inputName1, string &outputName) {

    notInput = NULL;
    setOutput1(outputName);
    setInput1(inputName1);
}
