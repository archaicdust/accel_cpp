#include <cctype>

#include "split.h"


bool space(char c)
{
    return isspace(c);
}


bool not_space(char c)
{
    return !isspace(c);
}

