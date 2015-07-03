
#include <map>
#include <vector>
#include <iostream>

#include "split.h"

using std::map;
using std::vector;
using std::string;
using std::istream;
using std::getline;


map<string, vector<int> >
xref(istream& in,
     vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    //read the next line
    while (getline(in, line)) {
        ++line_number;

        // break the input line into words
        vector<string> words = find_words(line);

        // remember that each word occurs on the line
        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    return ret;
}


int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    map<string, vector<int> > ret = xref(cin);

    for (map<string, vector<int> >::const_iterator it = ret.begin();
            it != ret.end(); ++it) {
        // write the words
        cout << it->first << " occurs one line(s): ";

        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;

        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }
        // wirte a new line to seperate each word from the next
        cout << endl;

        //
    }
}
