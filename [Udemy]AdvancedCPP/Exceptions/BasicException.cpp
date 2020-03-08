#include "BasicException.h"

#include <iostream>
#include <string>
using namespace std; // for convinience

void DefinitlyException()
{
    auto error = false;
    auto error2 = true;

    if (error)
    {
        throw "Something went wrong";
    }

    if (error2)
    {
        throw string("Wrong Again");
    }
}

void NestedFunctionAlsoCanCatchException()
{
    DefinitlyException();
}
