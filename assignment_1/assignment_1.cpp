// additional compile options -std=c++11
// g++ -std=c++11  assignment_1_mustafapaslı_131044032.cpp -o assignment_1_mustafapaslı_131044032


#include <iostream>

using namespace std;


//object struct for keep informations of objects
struct object{

    string objectName = "";
    int numberOfPieces = 0;

};

int countPlus(string&line); // find number of plus in line 

//ask base object property recursively and return calculating total cost
double recursiveQuestion(const string &objName); 

void takeInput(string & line,const string & baseObjName); //take object preperty 

int main() {

    string objectName;   //base object
    double totalCost;    //base object cost

    cout << "Define the object: " << endl;
    getline(cin,objectName);   //get base object name

    totalCost = recursiveQuestion(objectName);   //pass recursive func for object property

    cout << "Total cost of "<< objectName << " is " << totalCost << endl;  //print total cost

    return 0;
}

int countPlus(string&line){

    int plusNumber = 0;

    line.push_back('+') ; // push a plus to commend line end for finding reel number of objects

    for (int i = 0; i < line.length(); ++i)
        if(line[i] == '+')
            plusNumber++;

    return plusNumber;

}

void takeInput(string & line,const string & baseObjName){

    cout << "What is " << baseObjName << "?" << endl;
    getline(cin,line);

    while(line.length() == 0){ // for empty commend
        cout << "What is " << line << "?" << endl;
        getline(cin,line);
    }

}

double recursiveQuestion(const string &objName){

    string objectPro; //object property
    int objectsNumber;
    double total = 0.0;

    takeInput(objectPro,objName);

    size_t  found1 = objectPro.find('*');
    size_t  found2 = objectPro.find('+');

    if(found1 == string::npos && found2 == string::npos) // base case commend is a double
        total = stod(objectPro);

    else{ // pass objects recursive function

        int plusNumber = countPlus(objectPro);

        objectsNumber = plusNumber ;
        object objects[objectsNumber];

        int k = 0; // object index

        for (int j = 0; j < objectPro.length(); ++j) {

            if(objectPro[j] != '+' && objectPro[j] != ' ')
                objects[k].objectName.push_back(objectPro[j]); // parse objects property

            if(objectPro[j] == '+' && objectPro[j] != ' '){    //parse pieces from objects name

                size_t asterikIndex = objects[k].objectName.find('*');
                objects[k].numberOfPieces = (int)(stod(objects[k].objectName.substr(0, asterikIndex)));
                objects[k].objectName = objects[k].objectName.substr(asterikIndex+1,objects[k].objectName.length());

                k++;
            }
        }

        for (int i = 0; i < objectsNumber; ++i)
            total = total + objects[i].numberOfPieces * recursiveQuestion(objects[i].objectName);
    }
    return total;
}