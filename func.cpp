#include <iostream>
#include <vector>
#include <string>
#include "func.h"

using namespace std;

int func()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

	return 0;
}
