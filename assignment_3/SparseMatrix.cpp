//
// Created by mustafa paslı on 29.03.2018.
//

#include <sstream>
#include "SparseMatrix.h"
SparseMatrix::SparseMatrix() : largestIndex(0),
                               largestRowIndex(0),
                               numberOfElement(0) {

}

SparseMatrix::SparseMatrix(const string &fileName) : fileName(fileName),
                                                     numberOfElement(0),
                                                     largestIndex(0),
                                                     largestRowIndex(0) {

    ifstream inputFile;   // opening file
    inputFile.open(fileName);

    int readingIndex; // reading column number from file
    double readingData; // reading data from file
    char readingCh; // reading ':' character
    int lineNumber;// reading row number from file

    string line; // reading line from file

    Element readingElement; // keeps reading element from file

    while(getline(inputFile,line)){  // reading file line by line

        istringstream row(line); // converting line to string stream

        row >> lineNumber; // reading line number

        while(row >> readingIndex >> readingCh >> readingData){ // while loop for keeping column number and data after row number
            // fill element
            readingElement.setLineNumber(lineNumber);
            readingElement.setIndex(readingIndex);
            readingElement.setData(readingData);

            elements.push_back(readingElement); // put element to elements vector

            numberOfElement++;

            if(largestIndex < readingIndex){ // find largest index and change previous value
                largestIndex = readingIndex;
            }

            if(largestRowIndex < lineNumber){ // find largest row index and change previous value
                largestRowIndex = lineNumber;
            }

        }

    }

    inputFile.close();  // closing file
}

void SparseMatrix::sortMatrix() {

    vector <Element> sortingElements;

    for (int i = 0; i < largestRowIndex+1; ++i) { // sorting matrix elements by row and column number
        for (int j = 0; j < largestIndex+1; ++j) {
            for (int k = 0; k < numberOfElement; ++k) {
                if(elements[k].getLineNumber() == i && elements[k].getIndex() == j){
                    sortingElements.push_back(elements[k]);
                }
            }
        }
    }

    elements = sortingElements;
}

const SparseMatrix SparseMatrix::transpose() {

    SparseMatrix tMatrix;

    tMatrix = *this; // copy base matrix to tMatrix

    int temp;

    for (int i = 0; i < numberOfElement; ++i) { // changing row and column number

        temp = tMatrix.elements[i].getIndex();
        tMatrix.elements[i].setIndex(elements[i].getLineNumber());
        tMatrix.elements[i].setLineNumber(temp);

    }

    tMatrix.sortMatrix();

    return tMatrix;
}

const SparseMatrix operator-(const SparseMatrix &sm) {

    SparseMatrix negative;
    negative = sm;

    for (int i = 0; i < sm.numberOfElement; ++i) { // converting positive data to negative data
        negative.elements[i].setData(-negative.elements[i].getData());
    }

    return negative;
}

const vector<Element> &SparseMatrix::getElements() const {

    return elements;

}

double SparseMatrix::getDatabyIndexAndLine(int index, int line)const {

    for (int i = 0; i < numberOfElement; ++i) { //
        if(elements[i].getIndex() == index && elements[i].getLineNumber() == line){ // if data is not zero
            return elements[i].getData();
        }
    }

    return 0.0; // else return zero

}

SparseMatrix &SparseMatrix::operator = (const SparseMatrix &rightSide) {

    largestRowIndex = rightSide.largestRowIndex ;
    largestIndex = rightSide.largestIndex ;

    if(rightSide.numberOfElement != numberOfElement){ //resize if vectors has a different size
        numberOfElement = rightSide.numberOfElement;
        elements.resize(static_cast<unsigned long>(numberOfElement));
    }

    for (int i = 0; i < numberOfElement; ++i) {
        elements[i] = rightSide.elements[i];
    }

    return *this;

}

ostream &operator<<(ostream &outputStream, const SparseMatrix &sparseMatrix) {

    int lineNo = -1;

    for (int i = 0; i < sparseMatrix.numberOfElement; ++i) {

        if(sparseMatrix.getElements()[i].getLineNumber() != lineNo) { // if row numbers is same next element
            outputStream << sparseMatrix.getElements()[i].getLineNumber();
            outputStream << " ";
            lineNo = sparseMatrix.getElements()[i].getLineNumber();

        }

        outputStream << sparseMatrix.getElements()[i].getIndex();
        outputStream << ":";
        outputStream << sparseMatrix.getElements()[i].getData();
        outputStream << " ";

        // if row number is different next element
        if(sparseMatrix.getElements()[i+1].getLineNumber() != lineNo && i <sparseMatrix.numberOfElement-1) {

            outputStream << endl;
        }
    }

    return outputStream;
}

const SparseMatrix operator*(const SparseMatrix &sm1, const SparseMatrix &sm2) {

    SparseMatrix multipleMatrix;
    Element element;

    int min;

    if(sm1.largestIndex > sm2.largestRowIndex){
        min = sm2.largestRowIndex;
    }else
        min = sm1.largestIndex;

    vector <vector<double> > m1; // 2d double array for keeps sm1 matrix
    vector <vector<double> > m2; // 2d double array for keeps sm2 matrix
    vector <vector<double> > multiple; //  2d double array for sm1*sm2 matrix

    m1.resize(sm1.largestRowIndex+1); // resize array
    for (int i = 0; i < sm1.largestRowIndex+1 ; ++i) {
        m1[i].resize(sm1.largestIndex+1);
    }

    for (int j = 0; j < sm1.numberOfElement; ++j) { // fill array
        m1[sm1.elements[j].getLineNumber()][sm1.elements[j].getIndex()] = sm1.elements[j].getData();
    }

    m2.resize(sm2.largestRowIndex+1);
    for (int i = 0; i < sm2.largestRowIndex+1 ; ++i) {  // resize array
        m2[i].resize(sm2.largestIndex+1);
    }

    for (int j = 0; j < sm2.numberOfElement; ++j) { // fill array
        m2[sm2.elements[j].getLineNumber()][sm2.elements[j].getIndex()] = sm2.elements[j].getData();
    }

    multiple.resize(sm1.largestRowIndex+1); // resize array
    for (int i = 0; i < sm1.largestRowIndex+1 ; ++i) {
        multiple[i].resize(sm2.largestIndex+1);
    }

    for (int k = 0; k < sm1.largestRowIndex+1 ; ++k) { // calculate sm1 * sm2 and fill array
        for (int i = 0; i < sm2.largestIndex+1; ++i) {
            multiple[k][i] = 0.0;
            for (int j = 0; j < min+1; ++j) {
                multiple[k][i] = multiple[k][i]+(m1[k][j]*m2[j][i]);
            }
        }

    }


    for (int k = 0; k < sm1.largestRowIndex+1 ; ++k) { // fill multipleMatrix
        for (int i = 0; i < sm2.largestIndex+1; ++i) {
            if(multiple[k][i] != 0){
                element.setLineNumber(k);
                element.setIndex(i);
                element.setData(multiple[k][i]);
                multipleMatrix.elements.push_back(element);
                multipleMatrix.numberOfElement++;
                multipleMatrix.largestRowIndex = sm1.largestRowIndex;
                multipleMatrix.largestIndex = sm2.largestIndex;
            }
        }
    }

    return multipleMatrix;
}

const SparseMatrix operator+(const SparseMatrix &sm1, const SparseMatrix &sm2) {

    int highRowSize; // keeps size of row number
    int highColSize; // keeps size of columns number

    if(sm1.largestIndex > sm2.largestIndex){ // compare column number
        highColSize = sm1.largestIndex;
    }else
        highColSize = sm2.largestIndex;

    if(sm1.largestRowIndex > sm2.largestRowIndex){ // compare row number
        highRowSize = sm1.largestRowIndex;
    }else
        highRowSize = sm2.largestRowIndex;

    SparseMatrix sum;
    Element sumElm;

    for (int i = 0; i < highRowSize+1; ++i) {
        for (int j = 0; j < highColSize+1; ++j) {

            if(sm1.getDatabyIndexAndLine(j,i)+sm2.getDatabyIndexAndLine(j,i) != 0){ // fill sum matrix
                sumElm.setData(sm1.getDatabyIndexAndLine(j,i)+sm2.getDatabyIndexAndLine(j,i));
                sumElm.setIndex(j);
                sumElm.setLineNumber(i);
                sum.elements.push_back(sumElm);
                sum.numberOfElement++;

            }

        }
    }

    return sum;
}

const SparseMatrix operator-(const SparseMatrix &sm1, const SparseMatrix &sm2) {

    int highRowSize;
    int highColSize;

    if(sm1.largestIndex > sm2.largestIndex){
        highColSize = sm1.largestIndex;
    }else
        highColSize = sm2.largestIndex;

    if(sm1.largestRowIndex > sm2.largestRowIndex){
        highRowSize = sm1.largestRowIndex;
    }else
        highRowSize = sm2.largestRowIndex;

    SparseMatrix sum;
    Element sumElm;

    for (int i = 0; i < highRowSize+1; ++i) {
        for (int j = 0; j < highColSize+1; ++j) {

            if(sm1.getDatabyIndexAndLine(j,i)-sm2.getDatabyIndexAndLine(j,i) != 0){
                sumElm.setData(sm1.getDatabyIndexAndLine(j,i)-sm2.getDatabyIndexAndLine(j,i));
                sumElm.setIndex(j);
                sumElm.setLineNumber(i);
                sum.elements.push_back(sumElm);
                sum.numberOfElement++;

            }
        }
    }

    return sum;
}