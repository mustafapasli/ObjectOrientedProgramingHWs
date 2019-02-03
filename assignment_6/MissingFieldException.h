//
// Created by mustafa paslı on 19.05.2018.
//

#ifndef PA_06_MISSINGFIELDEXCEPTION_H
#define PA_06_MISSINGFIELDEXCEPTION_H

#include <exception>
#include <istream>

using namespace std;

class MissingFieldException : public exception{ // derived exception class

public:

    virtual const char* what() const throw() // return type of exception
    {
        return "Exception : missing field";
    }
};


#endif //PA_06_MISSINGFIELDEXCEPTION_H



