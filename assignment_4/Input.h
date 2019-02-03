//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_INPUT_H
#define CPP4_INPUT_H

#include "Gate.h"
#include <string>

using namespace std;

class Input : public Gate {

private:

    bool inputValue; // output result

public:

    Input(string name);

    void setInputValue(bool inputValue);

    bool calculate() ; // returns input value

};

#endif //CPP4_INPUT_H
