#include <iostream>

#include "Student_info.h"
#include "core.h"
#include "grad.h"
#include "handle.h"

using std::istream;

istream& Student_info::read(istream& is) 
{
    /**
    delete cp; // delete previous object, if any
    **/

    /*
     * allocate new object of the appropriate type
     * use Handle<T>(T*) to build a Handle<Core> from the pointer to that object
     * call Handle<T>::operator= to assign the Handle<Core> to the left-hand side
     */

    char ch;
    is >> ch; // get record type

    if (ch == 'U') {
        cp = new Core(is);
    } else {
        cp = new Grad(is);
    }
    return is;
}

/**
Student_info::Student_info(const Student_info& s): cp(0)
{
    if (s.cp) cp = s.cp->clone();
}


Student_info& Student_info::operator=(const Student_info& s)
{
    if (&s != this) {
        delete cp;
        if (s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }
    return *this;
}
**/

