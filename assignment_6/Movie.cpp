//
// Created by mustafa paslı on 19.05.2018.
//

#include "Movie.h"

const string &Movie::getTitle() const {
    return title;
}

const string &Movie::getDirector() const {
    return director;
}

const string &Movie::getYear() const {
    return year;
}

const string &Movie::getGenre() const {
    return genre;
}

const string &Movie::getStarring() const {
    return starring;
}

Movie::Movie() : title(""),
                 director(""),
                 year(""),
                 genre(""),
                 starring(""){}

Movie::Movie(const string &line) {

    size_t quetosIndexes[10];// keeps double quetos index in the data line

    int indexCounter = 0;

    for (int j = 0; j < line.length(); ++j) {// finding indexes from data line

        if (line[j] == '"') {

            quetosIndexes[indexCounter] = static_cast<size_t>(j);

            indexCounter++;

        }

    }
    // getting pieces from data line
    title = line.substr(quetosIndexes[0] + 1, quetosIndexes[1] - quetosIndexes[0] - 1);
    director = line.substr(quetosIndexes[2] + 1, quetosIndexes[3] - quetosIndexes[2] - 1);
    year = line.substr(quetosIndexes[4] + 1, quetosIndexes[5] - quetosIndexes[4] - 1);
    genre = line.substr(quetosIndexes[6] + 1, quetosIndexes[7] - quetosIndexes[6] - 1);
    starring = line.substr(quetosIndexes[8] + 1, quetosIndexes[9] - quetosIndexes[8] - 1);

}

ostream &operator<<(ostream &outputStream, const Movie &movie) {
    outputStream << '"' << movie.getTitle() << "\" \"" << movie.getDirector() << "\" \"" << movie.getYear()
                 << "\" \"" << movie.getGenre() << "\" \"" << movie.getStarring() << '"' << endl;

    return outputStream;
}

bool Movie::search(const string &str, const string &field) {

    size_t found;

    if(field == "title"){ // finding str in the field

        found = title.find(str);

        if(found != string::npos){
            return true;
        }

    }

    if(field == "director"){ // finding str in the field

        found = director.find(str);

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

    if(field == "starring"){ // finding str in the field

        found = starring.find(str);

        if(found != string::npos){
            return true;
        }

    }

    return false;
}



