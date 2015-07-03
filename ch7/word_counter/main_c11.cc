#include <map>
#include <string>
#include <iostream>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s;
    map<string, int> counters;

    while (cin >> s)
        ++counters[s];

    for (auto p: counters) {
        cout << p.first << "\t" << p.second << endl;
    }

    return 0;
}
