//
// Created by mustafa paslı on 5.05.2018.
//

#ifndef PA_05_FILE_H
#define PA_05_FILE_H


#include "BaseFile.h"

class File : public BaseFile {

public:
    File() { copyFile = false;} // default constructor

    File(const string &name, const string &dirName, string path);

    File(const File *file); // copy constructor

    File &operator = (const File*file);// assignment operator

    const string &getDirName() const;

    void setDirName(const string &dirName);

    bool isCopyFile() const;

    void setCopyFile(bool copyFile);

    ~File(); // destructor

private:

    string dirName; // belongs directory name

    bool copyFile;  // copy file status

};


#endif //PA_05_FILE_H
