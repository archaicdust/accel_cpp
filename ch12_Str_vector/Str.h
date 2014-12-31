#ifndef GUARD_STR_h
#define GUARD_STR_h

#include <iterator>
#include <cstring>
#include <algorithm>
#include <iostream>


class Str{
    friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef std::vector<char>::size_type size_type;

    // default constructor; create an empty Str
    Str() { }

    // create a Str contaning n copies of c
    Str(size_type n, char c): data(n ,c) { }

    // create a Str from a null-terminated array of char
    Str(const char *cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }

    // create a Str from the range denoted by iterators b and e
    template<class In> Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    size_type size() const { return data.size(); }

    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }

private:
    std::vector<char> data;
};


std::ostream& operator<<(std::ostream&, Str&);

Str operator+(const Str&, const Str&);

#endif

