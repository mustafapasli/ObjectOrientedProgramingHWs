//
// Created by mustafa paslı on 5.05.2018.
//

#include <iostream>
#include <fstream>
#include "Directory.h"
#include <string>
#include "File.h"

Directory::Directory() : BaseFile() {

    files = NULL;
    next = NULL;
    previousDir = NULL;
    rootDir = NULL;

    dirCapacity = 10;
    dirNumber = 0;

    fileCapacity = 10;
    usedFileCapacity = 0;

    copyDirectory = false;

    files = new File *[fileCapacity];
    next = new Directory *[dirCapacity];

    for (int k = 0; k < dirCapacity; ++k) {
        next[k] = NULL;
    }

    for (int l = 0; l < fileCapacity; ++l) {
        files[l] = NULL;
    }

}

Directory::Directory(const string &dirName, string **file, int numberOfLine, int numberOfSlash, string path,
                     Directory *prevDir, Directory *root)
        : BaseFile(dirName, path, true, false), previousDir(prevDir), rootDir(root) {


    files = NULL;
    next = NULL;
    previousDir = NULL;
    rootDir = NULL;

    dirCapacity = 10;
    dirNumber = 0;

    fileCapacity = 10;
    usedFileCapacity = 0;

    copyDirectory = false;

    files = new File *[fileCapacity];
    next = new Directory *[dirCapacity];

    for (int k = 0; k < dirCapacity; ++k) {
        next[k] = NULL;
    }

    for (int l = 0; l < fileCapacity; ++l) {
        files[l] = NULL;
    }

    for (int i = 0; i < numberOfLine; ++i) { // this for makes directory object recursively by files element
        for (int j = 0; j < numberOfSlash; ++j) {
            if (file[i][j] == dirName) {
                if (file[i][j + 2] != "-") { // makes next directory object and assigning to next pointer array
                    string temp;
                    temp = path;
                    temp.append("/");
                    temp.append(file[i][j + 1]);
                    next[dirNumber] = new Directory(file[i][j + 1], file, numberOfLine, numberOfSlash, temp, this,
                                                    rootDir);
                    dirNumber++;
                }
                if (file[i][j + 2] == "-") { // makes files object and assigning address to files pointer array
                    string temp;
                    temp = path;
                    temp.append("/");
                    temp.append(file[i][j + 1]);
                    files[usedFileCapacity] = new File(file[i][j + 1], file[i][j], temp);
                    usedFileCapacity++;
                }
            }
        }
    }
}

Directory::Directory(const Directory *dir) {

    setName(dir->getName());
    setFullPath(dir->getFullPath());
    setIsFile(dir->isIsFile());
    setIsDir(dir->isIsDir());

    rootDir = dir->rootDir;
    previousDir = dir->previousDir;

    usedFileCapacity = dir->usedFileCapacity;
    dirNumber = dir->dirNumber;

    files = new File *[fileCapacity];
    next = new Directory *[dirCapacity];

    for (int i = 0; i < fileCapacity; ++i) {
        files[i] = NULL;
    }

    for (int j = 0; j < dirCapacity; ++j) {
        next[j] = NULL;
    }

    for (int k = 0; k < usedFileCapacity; ++k) {  // calling recursively copy constructor
        files[k] = new File(dir->files[k]);
    }

    for (int l = 0; l < dirNumber; ++l) {
        next[l] = new Directory(dir->next[l]);
    }

}

Directory &Directory::operator=(const Directory *dir) {

    setName(dir->getName());
    setFullPath(dir->getFullPath());
    setIsFile(dir->isIsFile());
    setIsDir(dir->isIsDir());

    rootDir = dir->rootDir;
    previousDir = dir->previousDir;

    usedFileCapacity = dir->usedFileCapacity;
    dirNumber = dir->dirNumber;

    files = new File *[fileCapacity];
    next = new Directory *[dirCapacity];

    for (int i = 0; i < fileCapacity; ++i) {
        files[i] = NULL;
    }

    for (int j = 0; j < dirCapacity; ++j) {
        next[j] = NULL;
    }

    for (int k = 0; k < usedFileCapacity; ++k) {
        files[k] = dir->files[k];
    }

    for (int l = 0; l < dirNumber; ++l) {
        next[l] = dir->next[l];
    }

    return *this;
}

void Directory::printDir(string firstPath) const {

    ofstream output;

    output.open("output.txt", ios::out | ios::app);

    output << firstPath << endl;

    firstPath = firstPath + "/";

    for (int j = 0; j < usedFileCapacity; ++j) {        // printing files path to output.txt
        output << firstPath <<files[j]->getName() << endl;
    }

    for (int i = 0; i < dirNumber; ++i) {               // call next directories printDir.

        firstPath = firstPath + next[i]->getName();
        next[i]->printDir(firstPath);
    }

    output.close();

}

void Directory::printTree() const {
    cout << "|" << getName() << endl;
    printTree(1);  // calling printTree with tab number

}

void Directory::printTree(int tabNum) const {


    for (int i = 0; i < dirNumber; ++i) {
        for (int i = 0; i < tabNum; ++i) {
            cout << "|     ";
        }
        cout << "|" << next[i]->getName() << endl; // printing  directory name
        next[i]->printTree(tabNum + 1);

    }

    for (int j = 0; j < usedFileCapacity; ++j) {

        for (int i = 0; i < tabNum; ++i) {  // printing  files name
            cout << "|     ";
        }

        cout << "|" << files[j]->getName() << endl;
    }


}

void Directory::dlt(string path) {

    int numberOfSlash = 0;

    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == '/') {
            numberOfSlash++;
        }
    }

    if (numberOfSlash == 0) { // if there is not slash in path
        bool dltStatus = false;
        for (int i = 0; i < dirNumber; ++i) {

            if (next[i]->getName() == path) { // finding directory name and assigning NULL to index
                //delete next[i];
                next[i] = NULL;
                dltStatus = true;
            }

            if (dltStatus) { // shifting directory object in next array
                next[i] = next[i + 1];
            }
            if (i == dirNumber - 1 && dltStatus) {
                if (i != 0) {
                    //delete next[i];
                    next[i] = NULL;
                }
                dirNumber--;
            }

        }

        dltStatus = false;

        for (int i = 0; i < usedFileCapacity; ++i) { // finding file name

            if (files[i]->getName() == path) { // finding file name and assigning NULL to index
                //delete files[i];
                files[i] = NULL;
                dltStatus = true;
            }

            if (dltStatus) {
                files[i] = files[i + 1];
            }
            if (i == usedFileCapacity - 1 && dltStatus) { // shifting file object in files array
                if (i != 0) {
                    //delete files[i];
                    files[i] = NULL;
                }

                usedFileCapacity--;
            }

        }

    }

    if (numberOfSlash > 0) { // if there is slash in path

        string fileName;
        string folderPath;

        size_t lastSlashIndex = 0;

        for (int i = 0; i < path.length(); ++i) { // parsing path by last slash index
            if (path[i] == '/') {
                lastSlashIndex = static_cast<size_t>(i);
            }
        }

        folderPath = path.substr(1, lastSlashIndex - 1);
        fileName = path.substr(lastSlashIndex + 1, path.length());

        Directory *temp = dynamic_cast<Directory *>(find(folderPath)); // finding path and returning directory object
        temp->dlt(fileName); // calling delete function

    }
}

void Directory::copy(string path1, string path2) {

    int numberOfSlash1 = 0;
    int numberOfSlash2 = 0;

    for (int i = 0; i < path1.length(); ++i) {
        if (path1[i] == '/') {
            numberOfSlash1++;
        }
    }

    for (int i = 0; i < path2.length(); ++i) {
        if (path2[i] == '/') {
            numberOfSlash2++;
        }
    }

    if (numberOfSlash1 == 0 && numberOfSlash2 == 0) { // if there is not slash in paths

        for (int i = 0; i < dirNumber; ++i) {

            if (next[i]->getName() == path1) { // finding path in next
                for (int j = 0; j < dirNumber; ++j) {

                    if (next[j]->getName() == path2) {

                        next[j]->addDirectory(next[i]);

                        next[i]->copyDirectory = true;
                    }
                }
            }
        }

        for (int k = 0; k < usedFileCapacity; ++k) { // finding path in files

            if (files[k]->getName() == path1) {
                for (int j = 0; j < dirNumber; ++j) {

                    if (next[j]->getName() == path2) {

                        next[j]->addFile(files[k]);

                        files[k]->setCopyFile(true);

                    }
                }
            }
        }
    }


    if (numberOfSlash1 > 0 && numberOfSlash2 > 0) {  // if there is slash in path

        Directory *targetFolder = NULL;
        targetFolder = dynamic_cast<Directory *>(find(path2.erase(0, 1))); // find path2 object address

        BaseFile * temp = NULL;
        temp = find(path1.erase(0, 1)); // copy object address

        if (temp != NULL) { // add object to target
            if (temp->isIsDir()) {
                targetFolder->addDirectory(dynamic_cast<Directory *>(temp));
            }
            if (temp->isIsFile()) {
                targetFolder->addFile(dynamic_cast<File *>(temp));
            }
        }

    }

}

void Directory::addDirectory(Directory *dirAddress) {

    if(dirNumber == dirCapacity){ // if next's capacity is full
        Directory ** temp  = new Directory*[dirCapacity];
        for (int i = 0; i < dirCapacity; ++i) {
            temp[i] = next[i];
        }

        for (int j = 0; j < dirCapacity; ++j) {
            delete[](next[j]);
        }

        delete[](next);

        dirCapacity*=2;

        next = new Directory*[dirCapacity];

        for (int k = 0; k < dirNumber; ++k) {
            next[k] = temp[k];
        }

        for (int j = 0; j < dirNumber; ++j) {
            delete[](temp[j]);
        }

        delete[](temp);

    }
    next[dirNumber] = dirAddress;
    dirNumber++;

}

void Directory::addFile(File *fileAddress) {

    if(usedFileCapacity == fileCapacity){ // if files capacity is full
        File ** temp  = new File*[fileCapacity];
        for (int i = 0; i < fileCapacity; ++i) {
            temp[i] = files[i];
        }

        for (int j = 0; j < fileCapacity; ++j) {
            delete[](files[j]);
        }

        delete[](files);

        fileCapacity*=2;

        next = new Directory*[fileCapacity];

        for (int k = 0; k < usedFileCapacity; ++k) {
            files[k] = temp[k];
        }

        for (int j = 0; j < usedFileCapacity; ++j) {
            delete[](temp[j]);
        }

        delete[](temp);

    }

    files[usedFileCapacity] = fileAddress;
    usedFileCapacity++;

}

void Directory::move(string path1, string path2) {

    int numberOfSlash1 = 0;
    int numberOfSlash2 = 0;

    for (int i = 0; i < path1.length(); ++i) {
        if (path1[i] == '/') {
            numberOfSlash1++;
        }
    }

    for (int i = 0; i < path2.length(); ++i) {
        if (path2[i] == '/') {
            numberOfSlash2++;
        }
    }

    if (numberOfSlash1 == 0 && numberOfSlash2 == 0) { // if there is not slash in paths

        for (int i = 0; i < dirNumber; ++i) {

            if (next[i]->getName() == path1) {// finding path in next
                for (int j = 0; j < dirNumber; ++j) {

                    if (next[j]->getName() == path2) {
                        next[j]->addDirectory(next[i]);
                        dlt(next[i]->getName());
                    }
                }
            }
        }

        for (int k = 0; k < usedFileCapacity; ++k) {// finding path in files

            if (files[k]->getName() == path1) {
                for (int j = 0; j < dirNumber; ++j) {

                    if (next[j]->getName() == path2) {
                        next[j]->addFile(files[k]);
                        dlt(files[k]->getName());
                    }
                }
            }
        }
    }

    if (numberOfSlash1 > 0 && numberOfSlash2 > 0) {// if there is slash in path

        Directory *targetFolder = NULL;
        targetFolder = dynamic_cast<Directory *>(find(path2.erase(0, 1)));// find path2 object address

        BaseFile *temp = NULL;

        string nonSlashPath1 = path1.substr(1, path1.length());
        temp = find(nonSlashPath1);// copy object address

        if (temp != NULL) {  // add object to target
            if (temp->isIsDir()) {
                targetFolder->addDirectory(dynamic_cast<Directory *>(temp));
                dlt(path1); // delete path
            }
            if (temp->isIsFile()) {
                targetFolder->addFile(dynamic_cast<File *>(temp));
                dlt(path1); // delete path
            }
        }

    }

}

BaseFile *Directory::find(string path) {

    BaseFile *temp = NULL;

    if (path == getFullPath()) {
        return this;
    }

    for (int i = 0; i < dirNumber; ++i) { // finding path recursively

        if (next[i]->getFullPath() == path) {
            temp = next[i];
        }
    }

    for (int j = 0; j < usedFileCapacity; ++j) {
        if (files[j]->getFullPath() == path) {
            temp = files[j];
        }
    }

    if (temp == NULL) {
        for (int i = 0; i < dirNumber; ++i) {
            return next[i]->find(path);
        }
    }

    return temp;
}

Directory *Directory::cd(string path) {

    int numberOfSlash = 0;

    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == '/') {
            numberOfSlash++;
        }
    }

    if (numberOfSlash == 0) { // change directory with '.' and '..'

        if (path == ".") {
            return previousDir;
        }
        if (path == "..") {
            return rootDir;
        }

        for (int i = 0; i < dirNumber; ++i) {

            if (next[i]->getName() == path) {
                return next[i];
            }

        }

    } else { // full path
        if (rootDir == NULL) {

            Directory *temp = dynamic_cast<Directory *>(find(path.substr(1, path.length())));
            return temp;
        } else {
            Directory *temp = dynamic_cast<Directory *>(rootDir->find(path.substr(1, path.length())));
            return temp;
        }


    }

    return NULL;

}

Directory::~Directory() {

    // calling recursively destructor

    for (int i = 0; i < fileCapacity; ++i) {
        if (files[i] != NULL && files[i]->isCopyFile() == false) {
            delete (files[i]);
        }
    }

    delete[](files);

    for (int j = 0; j < dirCapacity; ++j) {
        if (next[j] != NULL && next[j]->copyDirectory == false) {
            delete (next[j]);
        }
    }
    delete[](next);

}





