//
// Created by mustafa paslı on 23.04.2018.
//

#include "Decoder.h"

Decoder::Decoder(string &outputName1, string &outputName2, string &outputName3, string &outputName4, string &inputName1,
                 string &inputName2) {

    decInput1 = NULL;
    decInput2 = NULL;

    setOutput1(outputName1);
    setOutput2(outputName2);
    setOutput3(outputName3);
    setOutput4(outputName4);

    setInput1(inputName1);
    setInput2(inputName2);

    out1 = new Output(false, getOutput1());
    out2 = new Output(false, getOutput2());
    out3 = new Output(false, getOutput3());
    out4 = new Output(false, getOutput4());

}

void Decoder::pointInp1(Gate *inp) {
    decInput1 = inp;
}

void Decoder::pointInp2(Gate *inp) {
    decInput2 = inp;
}

bool Decoder::calculate() {

    if (decInput1 != NULL && decInput2 != NULL) {


        if (decInput1->calculate() && decInput2->calculate()) { // 1 1

            out1->setOutputValue(false);
            out2->setOutputValue(false);
            out3->setOutputValue(false);
            out4->setOutputValue(true);

        }

        if (decInput1->calculate() && !decInput2->calculate()) { // 1 0

            out1->setOutputValue(false);
            out2->setOutputValue(false);
            out3->setOutputValue(true);
            out4->setOutputValue(false);


        }

        if (!decInput1->calculate() && decInput2->calculate()) { // 0 1

            out1->setOutputValue(false);
            out2->setOutputValue(true);
            out3->setOutputValue(false);
            out4->setOutputValue(false);


        }

        if (!decInput1->calculate() && !decInput2->calculate()) { // 0 0

            out1->setOutputValue(true);
            out2->setOutputValue(false);
            out3->setOutputValue(false);
            out4->setOutputValue(false);


        }

        return true;
    }

    return false;
}

void Decoder::setOut1(Output *out1) {
    Decoder::out1 = out1;
}

void Decoder::setOut2(Output *out2) {
    Decoder::out2 = out2;
}

void Decoder::setOut3(Output *out3) {
    Decoder::out3 = out3;
}

void Decoder::setOut4(Output *out4) {
    Decoder::out4 = out4;
}

Output *Decoder::getOut1() const {
    return out1;
}

Output *Decoder::getOut2() const {
    return out2;
}

Output *Decoder::getOut3() const {
    return out3;
}

Output *Decoder::getOut4() const {
    return out4;
}

Decoder::~Decoder() {

    delete decInput1;
    delete decInput2;

    delete out1;
    delete out2;
    delete out3;
    delete out4;

}
