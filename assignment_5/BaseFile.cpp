//
// Created by mustafa paslı on 5.05.2018.
//

#include "BaseFile.h"

BaseFile::BaseFile(const string &name,const string &fullPath,bool isDir, bool isFile)
        : name(name) ,fullPath(fullPath),isDir(isDir),isFile(isFile) {}

const string &BaseFile::getName() const {
    return name;
}

void BaseFile::setName(const string &name) {
    BaseFile::name = name;
}

bool BaseFile::isIsDir() const {
    return isDir;
}

void BaseFile::setIsDir(bool isDir) {
    BaseFile::isDir = isDir;
}

bool BaseFile::isIsFile() const {
    return isFile;
}

void BaseFile::setIsFile(bool isFile) {
    BaseFile::isFile = isFile;
}

const string &BaseFile::getFullPath() const {
    return fullPath;
}

void BaseFile::setFullPath(const string &fullPath) {
    BaseFile::fullPath = fullPath;
}



