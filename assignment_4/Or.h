//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_OR_H
#define CPP4_OR_H

#include "Gate.h"
#include <string>
#include <iostream>

using namespace std;

class Or : public Gate {

private:
    Gate *orInput1; // keeps input gate
    Gate *orInput2;

    bool calculation;// calculations result

public:

    // constructor for inputs name and outputs name

    Or(string &inputName1, string &inputName2, string &outputName);

    ~Or();

    void pointInp1(Gate *inp);// setter input pointer

    void pointInp2(Gate *inp);// setter input pointer

    bool calculate() ; // calculate boolean result and return
};

#endif //CPP4_OR_H
