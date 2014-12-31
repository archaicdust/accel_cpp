#include <iostream>

#include "Str.h"

using std::ostream;
using std::istream;


ostream& operator<<(ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}


istream& operator>>(std::istream& is, Str& s)
{
    // obliterate existing value(s)
    s.data.clear();

    char c;
    while (is.get(c) && isspace(c))
        ;

    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        // if we read whitespace, then put it back on the Str
        if (is)
            is.unget();
    }
    return is;
}


Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}


