//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_AND_H
#define CPP4_AND_H

#include <iostream>
#include <string>
#include "Gate.h"

using namespace std;

class And : public Gate {
private:

    Gate *andInput1; // keeps input gate
    Gate *andInput2;

    bool calculation; // calculations result

public:

    // constructor for inputs name and outputs name

    And(string &inputName1, string &inputName2, string &outputName);

    ~And();

    void pointInp1(Gate *inp); // setter input pointer

    void pointInp2(Gate *inp); // setter input pointer

    bool calculate() ; // calculate boolean result and return
};

#endif //CPP4_AND_H
