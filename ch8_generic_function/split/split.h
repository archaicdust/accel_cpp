#ifndef GUARD_split_h
#define GUARD_split_h

#include <string>

bool not_space(char);
bool space(char);

template <class Out>
void split(const std::string &str, Out os) {

    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks

        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        //copy the characters in [i, j)
        if ( i != str.end())
            *os++ = std::string(i, j);

        i = j;
    }
}

#endif
