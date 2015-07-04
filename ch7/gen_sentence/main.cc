#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

#include "nrand.h"
#include "split.h"

using std::string;
using std::vector;
using std::map;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::logic_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

void gen_aux(const Grammar&, const string&, vector<string>&);

Grammar read_grammar(istream&);
vector<string> gen_sentence(const Grammar& g);


Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line)) {
        vector<string> entry = split(line);
        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin()+ 1, entry.end()));
    }
    return ret;
}


vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}


bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}


void
gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        // fetch the set of possible rules
        const Rule_collection& c = it->second;

        const Rule& r = c[nrand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}


int main() {
    vector<string> sentence = gen_sentence(read_grammar(cin));

    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }

    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    return 0;
}
