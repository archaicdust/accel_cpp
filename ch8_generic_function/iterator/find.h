#ifndef GUARD_find_h
#define GUARD_find_h

template <class In, class X> In find(In begin, In end, const X &x)
{
    while (begin != end && *begin !=x)
        ++begin;
    return begin;
}

#endif
