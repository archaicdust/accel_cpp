#include <vector>
#include <algorithm>
#include <stdexcept>


template<class T>
T median(std::vector<T> v)
{
    typedef typename std::vector<T>::size_type vec_sz;
    /*
     * The use of typename in the definition of vec_zs:
     * tell the implementation that vector<T>::size_type is the name of a type,
     * even though the implementation doesn't yet know what type T represents.
     *
     * Whenever you have a type, such as vector<T>, that depends on a template parameter,
     * and you want to use a member of that type, such as size_type, that itself is a type,
     * you must precede the entire name by typename to let the implementation know to treat
     * the name as a type. Although the standard library ensures that vector<T>::size_type
     * is the name of a type for any T, the implementation, having no special knowledge of
     * the standard-library types, has no way of knowing this fact.
     *
     */

    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");

    std::sort(v.begin(), v.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid-1]) /2 : v[mid];
}
