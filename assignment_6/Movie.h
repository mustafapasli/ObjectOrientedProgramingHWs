//
// Created by mustafa paslı on 19.05.2018.
//

#ifndef PA_06_MOVIE_H
#define PA_06_MOVIE_H

#include <istream>

using namespace std;

class Movie {

public:

    Movie();// default constructor

    Movie(const string &line); // getting data line constructor

    bool search(const string & str, const string & field);// searches str in field

    friend ostream &operator<<(ostream &outputStream, const Movie &movie);// overloading redirecting operator

    const string &getTitle() const;

    const string &getDirector() const;

    const string &getYear() const;

    const string &getGenre() const;

    const string &getStarring() const;

private:

    string title;
    string director;
    string year;
    string genre;
    string starring;


};


#endif //PA_06_MOVIE_H
