//
// Created by mustafa paslı on 29.03.2018.
//

#include "SparseVector.h"

SparseVector::SparseVector():numberOfElement(0),largestIndex(0) {

}

SparseVector::SparseVector(const string &fileName):fileName(fileName),numberOfElement(0),largestIndex(0){

    ifstream inputFile;
    inputFile.open(fileName); // opening file

    Element readingElement; // keeps reading element from file

    int readingIndex; // reading column number from file
    double readingData; // reading data from file
    char readingCh; // reading ':' character

    while(!inputFile.eof()){ // reading file to end of file

        inputFile >> readingIndex;
        inputFile >> readingCh;
        inputFile >> readingData;

        readingElement.setData(readingData); // fill element
        readingElement.setIndex(readingIndex);

        elements.push_back(readingElement); // put element to elements vector

        numberOfElement++;

        if(readingIndex > largestIndex){ // find largest index and change previous value
            largestIndex = readingIndex;
        }

    }

    inputFile.close(); // closing file

}

double SparseVector::getDataByIndex(int index) const {

    for (int i = 0; i < numberOfElement; ++i) {
        if(elements[i].getIndex() == index){ // if data is non zero
            return elements[i].getData();
        }
    }

    return 0.0; // if data is zero
}

const SparseVector operator-(const SparseVector &sp) {

    SparseVector negative; // new SparseVector object for negative;
    negative = sp; // assignment receiving vector to negative vektor

    for (int i = 0; i < negative.numberOfElement; ++i) { // turning data to negative
        negative.elements[i].setData(-negative.elements[i].getData());
    }

    return negative;
}

const vector<Element> &SparseVector::getElements() const {
    return elements;
}

double dot(const SparseVector &sp1, const SparseVector &sp2) {

    double dotProduct = 0; // keeps sum of dots

    for (int i = 0; i < sp1.numberOfElement; ++i) {
        for (int j = 0; j < sp2.numberOfElement; ++j) {
            if(sp1.elements[i].getIndex() == sp2.elements[j].getIndex()){ // if vectors column index is same multiple data and sum

                dotProduct += sp1.elements[i].getData() * sp2.elements[i].getData();

            }
        }
    }

    return dotProduct;

}

SparseVector &SparseVector::operator=(const SparseVector &rightSide) {

    if(rightSide.numberOfElement != numberOfElement){ // if size of elements is not same,resize elements size
        numberOfElement = rightSide.numberOfElement;
        elements.resize(static_cast<unsigned long>(numberOfElement));
    }

    for (int i = 0; i < numberOfElement; ++i) { // assign elements right side to base object
        elements[i] = rightSide.elements[i];
    }

    largestIndex = rightSide.largestIndex;

    return *this;
}

ostream & operator<<(ostream &outputStream, const SparseVector &sparseVector) {

    for (int i = 0; i < sparseVector.numberOfElement; ++i) { // printing vector to output stream

        outputStream << sparseVector.getElements()[i].getIndex();
        outputStream << ":";
        outputStream << sparseVector.getElements()[i].getData();
        outputStream << " ";
    }

    return outputStream;

}

const SparseVector operator+(const SparseVector &sp1, const SparseVector &sp2) {

    int highSize; // keeps size of columns number

    if(sp1.largestIndex > sp2.largestIndex){ // check largest index of vectors
        highSize = sp1.largestIndex;
    }else
        highSize = sp2.largestIndex;

    SparseVector sum; // sum vector
    Element sumElm; // sum element

    for (int i = 0; i <= highSize; ++i) {


        if(sp1.getDataByIndex(i) + sp2.getDataByIndex(i) != 0){ // if sum is not zero,fill element data and index and push

            sumElm.setData(sp1.getDataByIndex(i)+sp2.getDataByIndex(i));
            sumElm.setIndex(i);
            sum.elements.push_back(sumElm);
            sum.numberOfElement++;

        }
    }

    return sum;
}

const SparseVector operator-(const SparseVector &sp1, const SparseVector &sp2) {

    int highSize;

    if(sp1.largestIndex > sp2.largestIndex){
        highSize = sp1.largestIndex;
    }else
        highSize = sp2.largestIndex;

    SparseVector sum;
    Element sumElm;

    for (int i = 0; i <= highSize; ++i) {


        if(sp1.getDataByIndex(i) - sp2.getDataByIndex(i) != 0){

            sumElm.setData(sp1.getDataByIndex(i)-sp2.getDataByIndex(i));
            sumElm.setIndex(i);
            sum.elements.push_back(sumElm);
            sum.numberOfElement++;

        }
    }

    return sum;
}