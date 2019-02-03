//
// Created by mustafa paslı on 9.05.2018.
//

#ifndef PA_05_FILEMANAGER_H
#define PA_05_FILEMANAGER_H

#include <fstream>
#include <sstream>
#include <istream>
#include "Directory.h"

using namespace std;

class FileManager {

public:

    FileManager();

    void readFiles();         // reads input.txt

    void findRoot();          // finds root directory

    void doCommands();        // reads commands.txt and does this commands

    void printStructure();    // prints paths to output.txt

    virtual ~FileManager();

private:

    ifstream files;           // files.txt

    ifstream commands;        // commands.txt

    ofstream output;          // output.txt

    string **fileStr;         // keeps address of files path element

    string root;              // keeps root name

    Directory *rootDir;       // keeps root address

    Directory *cd;            // keeps current directory address

    int numberOfLines;        // keeps line number of files.txt

    int numberOfSlashInLine;  // keeps slash number in paths for element number in a path

};


#endif //PA_05_FILEMANAGER_H
