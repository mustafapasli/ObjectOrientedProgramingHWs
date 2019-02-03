//
// Created by mustafa paslı on 5.05.2018.
//

#ifndef PA_05_DIRECTORY_H
#define PA_05_DIRECTORY_H


#include "BaseFile.h"
#include "File.h"
#include <string>

class Directory : public BaseFile {

public:

    Directory();                                                 // default constructor

    Directory(const string &dirName, string **file, int numberOfLine, int numberOfSlash, string path,
              Directory *prevDir, Directory *root);

    Directory(const Directory *dir);                             // copy constructor

    Directory &operator=(const Directory *dir);                  // assignment operator

    void printDir(string firstPath) const;                                       // prints paths to output.txt

    void printTree() const;                                      // prints file tree to screen

    void dlt(string path);                                       // deletes file or directory

    void copy(string path1, string path2);                       // copy path1 to path2

    void move(string path1, string path2);                       // move path1 to path2

    Directory *cd(string path);                                  // change current directory and return cd

    ~Directory();                                                // destructor


private:

    File **files;                                               // keeps files address
    Directory **next;                                           // keeps next directories address
    Directory *previousDir;                                     // keeps previous directory address
    Directory *rootDir;                                         // keeps root directory address

    int dirNumber;                                              // number of next directories
    int dirCapacity;                                            // capacity number of next directories

    int fileCapacity;                                           // number of files
    int usedFileCapacity;                                       // capacity number of files

    void printTree(int tabNum) const;                           // prints tab number for directory tree

    BaseFile *find(string path);                                // finds path and return address

    void addDirectory(Directory *dirAddress);                   // adds directory to next

    void addFile(File *fileAddress);                            // adds file to files

    bool copyDirectory ;                                 // keeps copy directory info


};


#endif //PA_05_DIRECTORY_H
