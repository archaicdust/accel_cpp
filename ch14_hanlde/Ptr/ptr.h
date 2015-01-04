#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include <cstddef>
#include <stdexcept>


template <class T> class Ptr {
public:
    // manage reference count as well as pointer
    Ptr(): refptr(new size_t(1)), p(0) { }
    Ptr(T *t): refptr(new size_t(1)), p(t) { }
    Ptr(const Ptr& h): refptr(h.refptr), p(h.p)
    {
        ++*refptr;
    }

    Ptr& operator=(const Ptr&);
    ~Ptr();

    operator bool() const { return p; }

    T& operator*() const
    {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ptr");
    }

    T* operator->() const
    {
        if (p)
            return p;
        throw std::runtime_error("unbound Ptr");
    }

    // copy the object conditionally when neeed
    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p->clone() : 0;
        }
    }

private:
    T* p;
    size_t* refptr;
};


template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
    ++*rhs.refptr;
    // free the left-hand side, destroy pointers if appropriate
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    // copy in values from the right-hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}


template<class T> Ptr<T>::~Ptr()
{
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

#endif

