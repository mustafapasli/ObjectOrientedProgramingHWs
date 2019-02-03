//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_OUTPUT_H
#define CPP4_OUTPUT_H

#include "Gate.h"
#include <iostream>
#include <string>

using namespace std;

class Output : public Gate {

    Gate *outputInput;// keeps input gate
    // calculations result
    bool outputValue;

public:

    // constructor for inputs name and outputs name
    Output(bool state, string name);

    void pointInp1(Gate *inp);// setter input pointer

    bool calculate() ;// calculate boolean result and return

    ~Output();

    void setOutputValue(bool outputValue);
};

#endif //CPP4_OUTPUT_H
