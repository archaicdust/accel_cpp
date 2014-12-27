#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
    // if there are arguments, write them
    if (argc > 1) {
        // declare i outside the for because we need it after the loop finishes
        int i;
        for (i = 1; i < argc-1 ; ++i)
            cout << argv[i] << " "; // argv[i] is a char*

        cout << argv[i] << endl;
    }
    return 0;
}

