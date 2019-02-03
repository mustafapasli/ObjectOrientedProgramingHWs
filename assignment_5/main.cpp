#include "FileManager.h"

int main() {

    FileManager structure;

    structure.readFiles();      // reads input.txt
    structure.findRoot();       // finds root directory
    structure.doCommands();     // reads commands.txt and does this commands
    structure.printStructure(); // prints paths to output.txt

    return 0;
}