#include <iostream>
#include <fstream>
#include <string>
#include "SparseVector.h"
#include "SparseMatrix.h"

using namespace std;

int main() {

    ofstream outfile;

    outfile.open("output.txt", ios::out | ios::trunc );

    //Creating a SparseVector from file
    SparseVector a1("a1.txt");

    SparseVector a2("a2.txt");

    outfile << "a1" << endl << a1 << endl << endl;

    outfile << "a2" << endl << a2 << endl << endl;

    //Binary operations and assignment
    a1 = a1 + a2;

    outfile<<"a1 + a2"<<endl<<a1<<endl << endl;

    //Dot product
    outfile<< "dot(a1,a1)" << endl << dot(a1,a1)<<endl << endl;

    //Creating SparseMatrix from file
    SparseMatrix m1("m1.txt");

    SparseMatrix m2("m2.txt");

    outfile << "m1" << endl << m1 << endl << endl;

    outfile << "m2" << endl << m2 << endl << endl;

    outfile << "m1+m2" << endl << m1+m2 << endl << endl;

    outfile << "m1-m1" << endl << m1-m1 << endl << endl;

    outfile << "-m1" << endl << (-m1) << endl << endl;

    //Transpose
    outfile<< "m2.transpose()" << endl << m2.transpose()<<endl << endl;

    m2 = m1 * m2;

    outfile << "m1 * m2" << endl << m2 << endl << endl;

    return 0;

}