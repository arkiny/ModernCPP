#include <iostream>
using namespace std; // for convinience

void DefinitlyException()
{
    auto error = true;

    if (error)
    {
        throw 8;
    }
}

int main()
{
    DefinitlyException();
    return 0;
}