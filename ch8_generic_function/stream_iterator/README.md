
1 2 3
5
6 7 8 9 hello world 1 2

istream_iterator<int>(cin)
  read values from the standard input until we
  hit end-of-file or an input that is not valid as an input

The standard library (in the <iterator> header) provides iterators that can be bound to
input and output streams.

The iterators for istream meet the requirements for input iterators,
and those for ostream s meet the requirements for output iterators.


# Usage

    $ make

    $ ./main < README.md
    1 2 3 5 6 7 8 9 
    ---
    12356789

# Input and output iterators

Not all iterators are associated with containers.

C++ input and output are typed operations:
When we read from a stream, we always say the type we expect to read,
although those types are often implicit in the operations that do the read.

getline(cin, s) // read data into a string

cin >> s.name >> s.midterm >> s.final // read a string and two doubles

