//
// Created by mustafa paslı on 9.05.2018.
//

#include <iostream>
#include "FileManager.h"

void FileManager::readFiles() {

    files.open("files.txt");         // opening files.txt

    string line;                     // temp line

    while (getline(files, line)) {   // getting line by line from file for  finding line number and finding slash number
        int count = 2;

        for (int i = 0; i < line.length(); ++i) {   // finding slash number
            if (line[i] == '/') {
                count++;
            }
        }

        if (count > numberOfSlashInLine) {
            numberOfSlashInLine = count;
        }

        numberOfLines++;   // finding line number
    }

    fileStr = new string *[numberOfLines];       // taking memory for files path elements
    for (int j = 0; j < numberOfLines; ++j) {
        fileStr[j] = new string[numberOfSlashInLine];
    }


    for (int j = 0; j < numberOfLines; ++j) {    // assigning '-' to all elements
        for (int i = 0; i < numberOfSlashInLine; ++i) {
            fileStr[j][i] = '-';
        }
    }

    int a = 0;  // counter a
    int b = 0;  // counter b

    files.clear();  // resetting EOF
    files.seekg(0, files.beg); // taking curser to beginning file

    while (getline(files, line)) {

        stringstream ss(line);  // converting line too stringstream for parsing
        string element;

        while (getline(ss, element, '/')) {  // parsing string by '/'
            fileStr[a][b] = element;
            b++;
        }
        b = 0;
        a++;
    }

    files.close(); // closing file


}

void FileManager::findRoot() {

    int flag = 0; // flag for same directory name

    for (int m = 0; m < numberOfLines; ++m) {
        flag = 0;

        for (int i = 0; i < numberOfLines && flag != 1; ++i) {
            flag = 0;

            for (int j = 1; j < numberOfSlashInLine && flag != 1; ++j) {

                if (fileStr[m][0] == fileStr[i][j]) { // if first directory name in the path is there  another element in the path
                    flag = 1;
                }
                if (i == numberOfLines - 1 && j == numberOfSlashInLine - 1) { // if for loop come to end of elements assigning root dir name
                    root = fileStr[m][0];
                }
            }
        }
    }

}

void FileManager::doCommands() {

    commands.open("commands.txt"); // opening commands.txt file

    rootDir = new Directory(root, fileStr, numberOfLines, numberOfSlashInLine, root, rootDir, rootDir);

    // make new Directory object

    rootDir->printTree(); // print to screen firs files structure tree
    cout << endl;

    cd = rootDir; // assigning root to current directory

    string commandLine;
    string path1;
    string path2;
    string command;

    while (getline(commands, commandLine)) {

        stringstream ss(commandLine);
        ss >> command;
        cout << command << " ";
        if (command == "copy") { // if first element in line is a "copy"
            ss >> path1 >> path2; // read path1 and path2
            cout << path1 << " " << path2 << endl;
            cd->copy(path1, path2); // calling command function

        }
        if (command == "move") {// if first element in line is a "move"
            ss >> path1 >> path2;// read path1 and path2
            cout << path1 << " " << path2 << endl;
            cd->move(path1, path2);
        }
        if (command == "delete") {// if first element in line is a "delete"
            ss >> path1;// read path1
            cout << path1 << endl;
            cd->dlt(path1); // calling command function
        }
        if (command == "cd") {// if first element in line is a "cd"
            ss >> path1;// read path1
            cout << path1 << endl;
            cd = cd->cd(path1); // calling command function
        }
    }

    cout << endl;

    rootDir->printTree(); // print to screen last tree

    commands.close(); // closing file

}

void FileManager::printStructure() {

    output.open("output.txt"); // opening and closing output.txt for creating new file
    output.close();

    rootDir->printDir(root); // prints to file paths

}

FileManager::~FileManager() {


    delete (rootDir);

    for (int k = 0; k < numberOfLines; ++k) {
        delete[](fileStr[k]);
    }

    delete[](fileStr);

}

FileManager::FileManager() {

    fileStr = NULL;

    root = "0";

    rootDir = NULL;

    cd = NULL;

    numberOfLines = 0;
    numberOfSlashInLine = 0;
}
