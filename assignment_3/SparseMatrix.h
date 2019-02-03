//
// Created by mustafa paslı on 29.03.2018.
//

#ifndef PA_03_SPARSEMATRIX_H
#define PA_03_SPARSEMATRIX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "SparseVector.h"

using namespace std;

class SparseMatrix{

public:

    SparseMatrix(); // default constructor

    SparseMatrix(const string &fileName); // constructor for read file

    void sortMatrix(); // sorts element by column and row number

    const SparseMatrix transpose();

    double getDatabyIndexAndLine(int index,int line)const; // Getter for elements data by index and line

    const vector<Element> &getElements() const;

    SparseMatrix& operator = (const SparseMatrix& rightSide);

    friend const SparseMatrix operator - (const SparseMatrix& sm);

    friend ostream& operator << (ostream& outputStream, const SparseMatrix& sparseMatrix);

    friend const SparseMatrix operator * (const SparseMatrix& sm1, const SparseMatrix& sm2);

    friend const SparseMatrix operator + (const SparseMatrix& sm1, const SparseMatrix& sm2);

    friend const SparseMatrix operator - (const SparseMatrix& sm1, const SparseMatrix& sm2);

private:

    string fileName;

    int largestIndex; // largest column number

    int largestRowIndex; // largest row number

    int numberOfElement; // number of keeping element

    vector <Element> elements; // element vector for non zero data

};


#endif //PA_03_SPARSEMATRİX_H
