#include "BasicException.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    try
    {
        NestedFunctionAlsoCanCatchException();
    }
    catch (int e)
    {
        cout << "Error code: " << e << endl;
    }
    catch (char const* e)
    {
        cout << "Error String : " << e << endl;
    }
    catch (string& e)
    {
        cout << "Erorr String : " << e << endl;
    }

    cout << "Still running" << endl;

    return 0;
}