//
// Created by mustafa paslı on 19.05.2018.
//

#ifndef PA_06_DUPLICATEENTRYEXCEPTION_H
#define PA_06_DUPLICATEENTRYEXCEPTION_H

#include <exception>
#include <istream>

using namespace std;

class DuplicateEntryException : public exception {  // derived exception class

public:

    virtual const char * what() const throw(){  // return type of exception
        return "Exception : duplicate entry ";
    }

};


#endif //PA_06_DUPLICATEENTRYEXCEPTION_H
