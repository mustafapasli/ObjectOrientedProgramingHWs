//
// Created by mustafa paslı on 19.05.2018.
//

#ifndef PA_06_MUSIC_H
#define PA_06_MUSIC_H

#include <istream>

using namespace std;


class Music {

public:

    Music();// default constructor

    Music(const string &line); // getting data line constructor

    const string &getTitle() const;

    const string &getArtists() const;

    const string &getYear() const;

    const string &getGenre() const;

    bool search(const string &str, const string &field);// searches str in field

    friend ostream &operator<<(ostream &outputStream, const Music &book);// overloading redirecting operator

private:

    string title;
    string artists;
    string year;
    string genre;

};


#endif //PA_06_MUSIC_H
