#ifndef GUARD_replace_h
#define GUARD_replace_h

template<class For, class X>
void replace(For beg, For end, const X &x, const X &y)
{
    while (beg != end) {
        if (*beg == x)
            *beg = y;
    ++beg;
    }
}

#endif
