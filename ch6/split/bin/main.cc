#include <string>
#include <iostream>

#include "split.h"

using std::string;
using std::vector;
using std::getline;
using std::cin;
using std::cout;
using std::endl;


int main()
{
    string  s;

    while (getline(cin, s)) {
        vector<string> v = split(s);

        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }
    return 0;
}

