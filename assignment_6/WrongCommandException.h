//
// Created by mustafa paslı on 20.05.2018.
//

#ifndef PA_06_WRONGCOMMANDEXCEPTION_H
#define PA_06_WRONGCOMMANDEXCEPTION_H

#include <exception>
#include <iostream>

using namespace std;

class WrongCommandException :public exception{ // derived exception class

public:
    virtual const char * what() const throw(){ // return type of exception

        return "Exception: command is wrong";

    }

};


#endif //PA_06_WRONGCOMMANDEXCEPTION_H
