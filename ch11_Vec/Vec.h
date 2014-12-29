#ifndef GUARD_VEC_H
#define GUARD_VEC_H

#include <cstddef>
#include <memory>
#include <algorithm>

template <class T> class Vec {
public:
    // interface
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(size_t n , const T& val = T()) { create(n , val); }

    Vec(const Vec& v) { create(v.begin(), v.end()); } // copy constructor

    Vec& operator=(const Vec&); // syntax sugar
    //Vec<T>& operator=(const Vec<T>&);

    ~Vec() { uncreate(); }

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    void push_back(const T& val) {
        if (avail == limit) // get space if needed
            grow();
        unchecked_append(val); // append the new element
    }

    size_type size() const { return avail - data; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    // implementation
    iterator data;    // first element in the Vec
    iterator avail;  // pointer to (one past) the last contructed element
    iterator limit;   // points to (one past) the last available element

    // facilities for memory allocation
    std::allocator<T> alloc; // object to handle memory allocation

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destory the elements in the array and free the memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T&);
};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) // syntax sugar
//Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
    // check for self-assignment
    if (&rhs != this) {
        uncreate(); // free the array in the left-hand side
        create(rhs.begin(), rhs.end()); // copy elements from the right-hand to the left-heand side
    }
    return *this;
}


template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}


template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}


template <class T>
void Vec<T>::uncreate()
{
    if (data) {
        // destroy (in reverse order) the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        // return all the space that was allocated
        alloc.deallocate(data, limit -data);
    }
    // reset pointers to indicate that Vec is empty again
    data = limit = avail = 0;
}


template <class T>
void Vec<T>::grow()
{
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}


template <class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}

#endif

