//
// Created by mustafa paslı on 19.05.2018.
//

#include "Music.h"

Music::Music() : title(""),
                 artists(""),
                 year(""),
                 genre("") {}

Music::Music(const string &line) {

    size_t quetosIndexes[8];// keeps double quetos index in the data line

    int indexCounter = 0;

    for (int j = 0; j < line.length(); ++j) {// finding indexes from data line

        if (line[j] == '"') {

            quetosIndexes[indexCounter] = static_cast<size_t>(j);

            indexCounter++;

        }

    }
    // getting pieces from data line
    title = line.substr(quetosIndexes[0] + 1, quetosIndexes[1] - quetosIndexes[0] - 1);
    artists = line.substr(quetosIndexes[2] + 1, quetosIndexes[3] - quetosIndexes[2] - 1);
    year = line.substr(quetosIndexes[4] + 1, quetosIndexes[5] - quetosIndexes[4] - 1);
    genre = line.substr(quetosIndexes[6] + 1, quetosIndexes[7] - quetosIndexes[6] - 1);

}

ostream &operator<<(ostream &outputStream, const Music &music) {

    outputStream << '"' << music.getTitle() << "\" \"" << music.getArtists() << "\" \"" << music.getYear()
                 << "\" \"" << music.getGenre() << '"' << endl;

    return outputStream;
}



const string &Music::getTitle() const {
    return title;
}

const string &Music::getArtists() const {
    return artists;
}

const string &Music::getYear() const {
    return year;
}

const string &Music::getGenre() const {
    return genre;
}

bool Music::search(const string &str, const string &field) {

    size_t found;

    if(field == "title"){ // finding str in the field

        found = title.find(str);

        if(found != string::npos){
            return true;
        }

    }

    if(field == "artists"){ // finding str in the field

        found = artists.find(str);

        if(found != string::npos){
            return true;
        }

    }

    if(field == "year"){ // finding str in the field

        found = year.find(str);

        if(found != string::npos){
            return true;
        }

    }

    if(field == "genre"){ // finding str in the field

        found = genre.find(str);

        if(found != string::npos){
            return true;
        }

    }

    return false;
}
