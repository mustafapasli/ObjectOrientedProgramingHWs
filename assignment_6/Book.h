//
// Created by mustafa paslı on 18.05.2018.
//

#ifndef PA_06_BOOK_H
#define PA_06_BOOK_H

#include <istream>

using namespace std;

class Book {

public:

    Book(); // default constructor

    Book(const string &line); // getting data line constructor

    const string &getTitle() const;

    const string &getAuthors() const;

    const string &getYear() const;

    const string &getTags() const;

    bool search(const string &str, const string &field); // searches str in field

    friend ostream &operator << (ostream & outputStream, const Book & book); // overloading redirecting operator

private:

    string title;
    string authors;
    string year;
    string tags;

};


#endif //PA_06_BOOK_H
