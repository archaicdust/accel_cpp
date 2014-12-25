#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

#include "url_finder.h"


using std::vector;
using std::string;
using std::find_if;
using std::isalnum;
using std::isalpha;


bool not_url_char(char);
string::const_iterator url_beg(string::const_iterator, string::const_iterator);
string::const_iterator url_end(string::const_iterator, string::const_iterator);


vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b= s.begin(), e = s.end();

    while (b != e) {
        b = url_beg(b, e);
        if (b != e) {
            iter after = url_end(b,e);

            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;
}


string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}


bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.!*'(),'";

    return !(isalnum(c) ||
            find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks where the seperator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // make sure the seperator isn't at the begining or end of the line
        if (i != b && i + sep.size() != e) {
            // beg marks the begining of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate character before and after the se
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        // the seperator we found wasn't part of a URL advance i past this seperator
        i += sep.size();
    }
    return e;
}

