
# grade_homework_average.cc

    $ make grade_homework_average

# grade_homework_mean.cc

    $ make grade_homework_mean


# The value of cin

cin has type istream

    if (cin >> x) {/*...*/}

    has the same meaning as

    cin >> x;
    if (cin) {/*...*/}

When
 - reached the end of the input file
 - encountered input that is not compatible with the type the varible we are trying to read
 - the system detected a hardware failure on the input deviceo

read from a stream can be unsuccesful.

Once we have failed to read from a stream,
futher attempts to read from that stream will fail
until we reset the stream. ( cin.clear() )

