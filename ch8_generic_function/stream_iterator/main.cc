#include <vector>

#include <iostream>

#include <algorithm>

#include <iterator>

using std::vector;
using std::copy;

using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;

using std::endl;


int main() {
    vector<int> v;

    // read ints from the standard input and append to them to v
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
            back_inserter(v));

    /*
     * istream_iterator<int>(cin) constructs a new istream_iterator, bound to cin,
     * that expects to read value of type
     *
     * istream_iterator<int>() creates a default (empty) istream_iterator,
     * which is not bound to any file.
     *
     */

    // write the elements of v each separated from other by a space
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    cout << endl << "---" << endl;

    // no seperation between elements
    copy(v.begin(), v.end(), ostream_iterator<int>(cout));
}
