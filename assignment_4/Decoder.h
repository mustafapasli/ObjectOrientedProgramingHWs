//
// Created by mustafa paslı on 23.04.2018.
//

#ifndef CPP4_DECODER_H
#define CPP4_DECODER_H

#include "Gate.h"
#include "Output.h"

class Decoder : public Gate {

private:
    Gate *decInput1; // keeps input gate
    Gate *decInput2;

    Output *out1; // keep outputs gate
    Output *out2;
    Output *out3;
    Output *out4;

public:

    // constructor for inputs name and outputs name

    Decoder(string &outputName1, string &outputName2, string &outputName3, string &outputName4, string &inputName1,
            string &inputName2);

    ~Decoder();

    void setOut1(Output *out1); // setter for outputs

    void setOut2(Output *out2);

    void setOut3(Output *out3);

    void setOut4(Output *out4);

    Output *getOut1() const; // getter for outputs

    Output *getOut2() const;

    Output *getOut3() const;

    Output *getOut4() const;

    void pointInp1(Gate *inp); // setter input pointer

    void pointInp2(Gate *inp); // setter input pointer

    bool calculate() ; // calculate boolean result and return

};

#endif //CPP4_DECODER_H
