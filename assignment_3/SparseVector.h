//
// Created by mustafa paslı on 29.03.2018.
//

#ifndef PA_03_SPARSEVECTOR_H
#define PA_03_SPARSEVECTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Element.h"

using namespace std;

class SparseVector{

public:

    SparseVector(); // default constructor

    SparseVector(const string &fileName); // constructor for read file

    const vector<Element> &getElements() const;

    double getDataByIndex(int index) const; // Getter for elements data by index

    SparseVector& operator = (const SparseVector& rightSide);

    friend const SparseVector operator - (const SparseVector& sp);

    friend double dot(const SparseVector& sp1, const SparseVector& sp2);

    friend ostream& operator << (ostream& outputStream,const SparseVector& sparseVector);

    friend const SparseVector operator + (const SparseVector& sp1, const SparseVector& sp2);

    friend const SparseVector operator - (const SparseVector& sp1, const SparseVector& sp2);

private:

    int largestIndex;  // largest column number

    int numberOfElement; // number of keeping element

    string fileName;

    vector <Element> elements; // element vector for non zero data

};


#endif //PA_03_SPARSEVECTOR_H
