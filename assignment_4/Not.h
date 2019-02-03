//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_NOT_H
#define CPP4_NOT_H

#include "Gate.h"

class Not : public Gate {
private:
    Gate *notInput; // keeps input gate

public:

    // constructor for inputs name and outputs name

    Not(string &inputName1, string &outputName);

    void pointInp1(Gate *inp);// setter input pointer

    bool calculate(); // calculate boolean result and return

    ~Not();
};


#endif //CPP4_NOT_H
