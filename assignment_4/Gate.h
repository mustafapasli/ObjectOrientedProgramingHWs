//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_GATE_H
#define CPP4_GATE_H
#include <string>

using namespace std;

class Gate { // abstract base class

public:

    virtual ~Gate() {}

    virtual bool calculate() = 0; // calculates output result

    const string &getOutput1() const;

    void setOutput1(const string &output1);

    const string &getOutput2() const;

    void setOutput2(const string &output2);

    const string &getOutput3() const;

    void setOutput3(const string &output3);

    const string &getOutput4() const;

    void setOutput4(const string &output4);

    const string &getInput1() const;

    void setInput1(const string &input1);

    const string &getInput2() const;

    void setInput2(const string &input2);

private:

    // keeps output names
    string output4;
    string output3;
    string output2;
    string output1;

    // keeps input names
    string input2;
    string input1;
};

#endif //CPP4_GATE_H
