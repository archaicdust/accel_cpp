#include <iostream>

#include "Vec.h"


int main()
{
    Vec<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);

    for (Vec<int>::iterator it=v.begin(); it != v.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
