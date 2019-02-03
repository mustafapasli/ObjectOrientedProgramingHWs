//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_FLIPFLOP_H
#define CPP4_FLIPFLOP_H

#include <string>
#include "Gate.h"

class Flipflop : public Gate {

private:

    Gate *ffInput; // keeps input gate
    bool formerOut;
    int counter; // keep calculate function running time

public:

    // constructor for inputs name and outputs name

    Flipflop(string &inputName1, string &outputName);

    void pointInp1(Gate *inp);// setter input pointer

    bool calculate(); // calculate boolean result and return

    void counterReset(); // reset counter to zero

    ~Flipflop();


};

#endif //CPP4_FLIPFLOP_H
