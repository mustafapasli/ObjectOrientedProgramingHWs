#include <iostream>
#include <algorithm> // sort function
#include <fstream>
#include <sstream>   // istringstream
#include "Catalog.h"
#include "Catalog.cpp"

using namespace std;

int main() {

    ifstream dataFile("data.txt");  // opening require files
    ifstream commandFile("commands.txt");
    ofstream outputFile("output.txt", ios::app);

    string catalogName;

    getline(dataFile, catalogName); // getting catalog type
    dataFile.close();  // closing file

    string line;  // getting line from command.txt
    string command; // command type
    string name; // searching word
    string field; // field name
    string in; // in word on the middle line

    if (catalogName == "book") { // if catalog name is book

        Catalog<Book> books(catalogName); // creating templete object for books

        books.getDataFromFile();  // getting data from file
        books.printUniqueEntry();  // print to output file number of unique entry

        while (getline(commandFile, line)) { // get commands line by line

            try {

                istringstream ss(line); // printing line to buffer

                ss >> command; // taking command from line

                if (command == "search") { // if command is search

                    ss >> name >> in >> field; // pass "in" word from line and get field

                    bool searchStatus = false; // keep search status for wrong format exception

                    for (int i = 0; i < books.size(); ++i) { // range books array for serch word in field
                        if (books[i].search(name.substr(1, name.length() - 2), field.substr(1, field.length() - 2))) {
                            outputFile << line << endl; // print  command line to output.txt
                            outputFile << books[i]; // print line to output.txt
                            searchStatus = true; // changing search status
                        }

                    }

                    if (!searchStatus) // if searching word is not found
                        throw (WrongCommandException());

                } else if (command == "sort") { // if firs word is sort in line


                    ss >> field; // getting field name

                    bool sortStatus = false; // sort status

                    if (field.substr(1, field.length() - 2) == "title") { // if field is title
                        outputFile << line << endl; // print command line to output.txt
                        sort(books.getData().begin(), books.getData().end(), books.compareBookTitle); // sort books by title
                        sortStatus = true; // change sort status
                    }

                    if (field.substr(1, field.length() - 2) == "authors") {// if field is authors
                        outputFile << line << endl;// print command line to output.txt
                        sort(books.getData().begin(), books.getData().end(), books.compareBookAuthors);// sort books by authors
                        sortStatus = true; // change sort status
                    }

                    if (field.substr(1, field.length() - 2) == "year") {// if field is year
                        outputFile << line << endl;// print command line to output.txt
                        sort(books.getData().begin(), books.getData().end(), books.compareBookYear);// sort books by title
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "tags") {// if field is tags
                        outputFile << line << endl;// print command line to output.txt
                        sort(books.getData().begin(), books.getData().end(), books.compareBookTags);// sort books by title
                        sortStatus = true; // change sort status
                    }

                    if (!sortStatus) // if field is not founded
                        throw (WrongCommandException());

                    books.printData(); // print sorting lines to output.txt

                } else { // sort or search is not founded in commend line

                    throw (WrongCommandException());
                }

            } catch (WrongCommandException &e) { // catching exception
                outputFile << e.what() << endl;
                outputFile << line << endl;
            }

        }

    }
    // after that it continues same

    if (catalogName == "music") {

        Catalog<Music> musics(catalogName);

        musics.getDataFromFile();
        musics.printUniqueEntry();

        while (getline(commandFile, line)) {

            try {

                istringstream ss(line);

                ss >> command;

                if (command == "search") {

                    ss >> name >> in >> field;

                    bool searchStatus = false;

                    for (int i = 0; i < musics.size(); ++i) {
                        if (musics[i].search(name.substr(1, name.length() - 2), field.substr(1, field.length() - 2))) {
                            outputFile << line << endl;
                            outputFile << musics[i];
                            searchStatus = true;
                        }
                    }

                    if (!searchStatus)
                        throw (WrongCommandException());

                } else if (command == "sort") {

                    ss >> field;

                    bool sortStatus = false;

                    if (field.substr(1, field.length() - 2) == "title") {
                        outputFile << line << endl;
                        sort(musics.getData().begin(), musics.getData().end(), musics.compareMusicTitle);
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "artists") {
                        outputFile << line << endl;
                        sort(musics.getData().begin(), musics.getData().end(), musics.compareMusicArtists);
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "year") {
                        outputFile << line << endl;
                        sort(musics.getData().begin(), musics.getData().end(), musics.compareMusicYear);
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "genre") {
                        outputFile << line << endl;
                        sort(musics.getData().begin(), musics.getData().end(), musics.compareMusicGenre);
                        sortStatus = true;
                    }


                    if (!sortStatus)
                        throw (WrongCommandException());

                    musics.printData();

                } else {

                    throw (WrongCommandException());
                }

            } catch (WrongCommandException &e) {

                outputFile << e.what() << endl;
                outputFile << line << endl;
            }

        }

    }

    if (catalogName == "movie") {

        Catalog<Movie> movies(catalogName);

        movies.getDataFromFile();
        movies.printUniqueEntry();

        while (getline(commandFile, line)) {

            try {

                istringstream ss(line);
                ss >> command;

                if (command == "search") {

                    ss >> name >> in >> field;

                    bool searchStatus = false;

                    for (int i = 0; i < movies.size(); ++i) {
                        if (movies[i].search(name.substr(1, name.length() - 2), field.substr(1, field.length() - 2))) {
                            outputFile << line << endl;
                            outputFile << movies[i];
                            searchStatus = true;
                        }
                    }

                    if (!searchStatus)
                        throw (WrongCommandException());

                } else if (command == "sort") {

                    ss >> field;

                    bool sortStatus = false;

                    if (field.substr(1, field.length() - 2) == "year") {
                        outputFile << line << endl;
                        sort(movies.getData().begin(), movies.getData().end(), movies.compareMovieYear);
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "title") {
                        outputFile << line << endl;
                        sort(movies.getData().begin(), movies.getData().end(), movies.compareMovieTitle);
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "director") {
                        outputFile << line << endl;
                        sort(movies.getData().begin(), movies.getData().end(), movies.compareMovieDirector);
                        sortStatus = true;
                    }

                    if (field.substr(1, field.length() - 2) == "genre") {
                        outputFile << line << endl;
                        sort(movies.getData().begin(), movies.getData().end(), movies.compareMovieGenre);
                        sortStatus = true;
                    }


                    if (field.substr(1, field.length() - 2) == "starring") {
                        outputFile << line << endl;
                        sort(movies.getData().begin(), movies.getData().end(), movies.compareMovieStarring);
                        sortStatus = true;
                    }

                    if (!sortStatus)
                        throw (WrongCommandException());

                    movies.printData();

                } else {

                    throw (WrongCommandException());
                }

            } catch (WrongCommandException &e) {

                outputFile << e.what() << endl;
                outputFile << line << endl;
            }
        }
    }

    outputFile.close(); // closing output file

    return 0;
}