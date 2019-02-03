//
// Created by mustafa paslı on 19.05.2018.
//

#include <fstream>
#include <iostream>
#include "Catalog.h"
template<class T>
Catalog<T>::Catalog() {

    vectorSize = 0;

}

template<class T>
void Catalog<T>::push_back(T item) {

    data.push_back(item);
    vectorSize++;

}

template<class T>
int Catalog<T>::size() {
    return vectorSize;
}

template<class T>
T &Catalog<T>::operator[](int index) {
    return data[index];
}

template<class T>
Catalog<T>::Catalog(const string &catalogName):catalogName(catalogName) {
    vectorSize = 0;
}

template<class T>
void Catalog<T>::getDataFromFile() {

    ifstream dataFile;
    dataFile.open("data.txt");   // opening data.txt

    ofstream outputFile;
    outputFile.open("output.txt"); // opening output.txt

    outputFile << "Catalog Read : " << catalogName << endl; // printing catalog type to output file

    string line; // keeps data line

    int numberOfQuotes = 0; // number of double quotes in the data line
    int maxNumberOfQuotes;  // keeps number of max quotes in the data line

    if (catalogName == "movie") {// if catalog is movie catalog
        maxNumberOfQuotes = 10;
    } else                       // for others
        maxNumberOfQuotes = 8;


    getline(dataFile, line);     // seek catalog type line

    while (getline(dataFile, line)) { // getting data line by line

        try {

            for (int i = 0; i < line.length(); ++i) { // counting quotes
                if (line[i] == '"') {
                    numberOfQuotes++;
                }
            }

            if (numberOfQuotes != maxNumberOfQuotes) { // if there is missing quotes
                throw (MissingFieldException());
            }


            numberOfQuotes = 0; // resetting number of quotes for next data


            T temp(line); // create T type object with passing line constructor

            for (int i = 0; i < vectorSize; ++i) {  // checking duplicate entry
                if (temp.getTitle() == data[i].getTitle()) { // if titles are same
                    throw (DuplicateEntryException());
                }
            }

            push_back(temp); // add temp to data vector


        } catch (DuplicateEntryException &e) { // catching duplicate entry exception

            outputFile << e.what() << endl;
            outputFile << line << endl;
        }

        catch (MissingFieldException &e) {  // catching missing field exception

            outputFile << e.what() << endl;
            outputFile << line << endl;
            numberOfQuotes = 0;

        }

    }

    outputFile.close(); // closing file
    dataFile.close();


}

template<class T>
void Catalog<T>::printData() {

    ofstream outputFile;

    outputFile.open("output.txt", ios::app);

    // print data output with using iterator

    for (typename vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
        outputFile << *it;
    }

    outputFile.close();

}

template<class T>
vector<T> &Catalog<T>::getData() {
    return data;
}

template<class T>
void Catalog<T>::printUniqueEntry() {

    ofstream outputFile;

    outputFile.open("output.txt", ios::app);

    outputFile << vectorSize << " unique entries" << endl; // printing unique entry

    outputFile.close();

}


