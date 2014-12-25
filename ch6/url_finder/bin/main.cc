#include <string>
#include <vector>
#include <iostream>

#include "url_finder.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;


int main()
{
    string s = "http://hello htpps://world hello world";
    vector<string> url = find_urls(s);

    cout << "URL:" << endl;
    for (vector<string>::const_iterator iter = url.begin();
         iter != url.end(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}
