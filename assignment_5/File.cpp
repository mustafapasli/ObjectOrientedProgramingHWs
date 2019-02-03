//
// Created by mustafa paslı on 5.05.2018.
//

#include "File.h"


File::File(const string &name, const string & dirName,string path) : BaseFile(name,path,false, true) {

    File::dirName = dirName;
    setFullPath(path);

}

File &File::operator=(const File *file) {

    setName(file->getName());
    setFullPath(file->getFullPath());
    setIsFile(file->isIsFile());
    setIsDir(file->isIsDir());

    dirName = file->dirName;

    return *this;
}

File::File(const File *file) {

    setName(file->getName());
    setFullPath(file->getFullPath());
    setIsFile(file->isIsFile());
    setIsDir(file->isIsDir());

    dirName = file->dirName;

}

const string &File::getDirName() const {
    return dirName;
}

void File::setDirName(const string &dirName) {
    File::dirName = dirName;
}

bool File::isCopyFile() const {
    return copyFile;
}

void File::setCopyFile(bool copyFile) {
    File::copyFile = copyFile;
}

File::~File() {

}

