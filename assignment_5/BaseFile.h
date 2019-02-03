//
// Created by mustafa paslı on 5.05.2018.
//

#ifndef PA_05_BASEFILE_H
#define PA_05_BASEFILE_H

#include <string>

using namespace std;

class BaseFile {

public:

    BaseFile() : isDir(false), isFile(false) {}

    BaseFile(const string &name, const string &fullPath, bool isDir, bool isFile);

    const string &getName() const;

    void setName(const string &name);

    bool isIsDir() const;

    void setIsDir(bool isDir);

    bool isIsFile() const;

    void setIsFile(bool isFile);

    const string &getFullPath() const;

    void setFullPath(const string &fullPath);

    virtual ~BaseFile() {};

private:

    string fullPath; // long path of file or directory

    string name; // directory or file name

    bool isDir;

    bool isFile;

};


#endif //PA_05_BASEFILE_H
