//
// Created by mustafa paslı on 19.05.2018.
//

#ifndef PA_06_CATALOGREADER_H
#define PA_06_CATALOGREADER_H

#include <vector>
#include <string>
#include "MissingFieldException.h"
#include "WrongCommandException.h"
#include "DuplicateEntryException.h"

#include "Book.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

template<class T>
class Catalog { // template Catalog class for keeping book, music and movie classes

public:

    Catalog(); // default constructor

    Catalog(const string &catalogName); // taking catalog name constructor

    void getDataFromFile(); // gets line by line data from

    void printData(); // prints data line to output file

    void printUniqueEntry(); // prints number of unique entry to output file

    void push_back(T item); // takes item and adds end of the data

    int size(); // return size

    vector<T> &getData(); // getter for data

    T &operator[](int index); // index operator for catalog data

    // compare functions for using sort function in main

    static bool compareBookTitle(const Book &lhs, const Book &rhs) { return lhs.getTitle() < rhs.getTitle(); }

    static bool compareBookAuthors(const Book &lhs, const Book &rhs) { return lhs.getAuthors() < rhs.getAuthors(); }

    static bool compareBookYear(const Book &lhs, const Book &rhs) { return lhs.getYear() < rhs.getYear(); }

    static bool compareBookTags(const Book &lhs, const Book &rhs) { return lhs.getTags() < rhs.getTags(); }

    static bool compareMusicTitle(const Music &lhs, const Music &rhs) { return lhs.getTitle() < rhs.getTitle(); }

    static bool compareMusicArtists(const Music &lhs, const Music &rhs) { return lhs.getArtists() < rhs.getArtists(); }

    static bool compareMusicYear(const Music &lhs, const Music &rhs) { return lhs.getYear() < rhs.getYear(); }

    static bool compareMusicGenre(const Music &lhs, const Music &rhs) { return lhs.getGenre() < rhs.getGenre(); }

    static bool compareMovieYear(const Movie &lhs, const Movie &rhs) { return lhs.getYear() < rhs.getYear(); }

    static bool compareMovieTitle(const Movie &lhs, const Movie &rhs) { return lhs.getTitle() < rhs.getTitle(); }

    static bool compareMovieDirector(const Movie &lhs, const Movie &rhs) { return lhs.getDirector() < rhs.getDirector(); }

    static bool compareMovieGenre(const Movie &lhs, const Movie &rhs) { return lhs.getGenre() < rhs.getGenre(); }

    static bool compareMovieStarring(const Movie &lhs, const Movie &rhs) { return lhs.getStarring() < rhs.getStarring(); }

private:

    vector<T> data;     // data vector
    int vectorSize;     // vector size
    string catalogName; // catalog name

};


#endif //PA_06_CATALOGREADER_H
