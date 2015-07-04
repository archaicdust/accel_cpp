#ifndef GUARD_reverse_h
#define GUARD_reverse_h

template <class Type>
void swap(Type &a, Type &b) {
  Type tmp = a;
  a = b;
  b = tmp;
}


template<class Bi> void reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

#endif
