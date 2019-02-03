//
// Created by mustafa paslı on 6.04.2018.
//

#ifndef PA_03_ELEMENT_H
#define PA_03_ELEMENT_H

// ELement class keeps data, row and column number for vector and matrix.

class Element{

public:

    Element():data(0.0),index(0),lineNumber(0){};

    int getIndex() const;

    void setIndex(int index);

    double getData() const;

    void setData(double data);

    int getLineNumber() const;

    void setLineNumber(int lineNumber);

private:

    double data;

    int index; // column number

    int lineNumber; // row number

};

#endif //PA_03_ELEMENT_H
