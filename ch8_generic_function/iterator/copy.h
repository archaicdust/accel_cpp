#ifndef GUARD_copy_h
#define GUARD_copy_h

template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

#endif
