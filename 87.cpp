#include <string>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

struct SubPair {
    int b1, b2, n;
    SubPair(int a, int b, int c) : b1(a), b2(b), n(c) {}

    bool operator < (const SubPair &x) const {
        if (b1 != x.b1) {
            return b1 < x.b1;
        }
        if (b2 != x.b2) {
            return b2 < x.b2;
        }
        return n < x.n;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        const int n = s1.size();
        return isScramble(s1, s2, 0, 0, n);
    }

    bool isScramble(const string &s1, const string &s2, int b1, int b2, int l) {
        SubPair test(b1, b2, l);
        if (table.find(test) != table.end()) {
            return table[test] = false;
        }
        
        string t1 = s1.substr(b1, l), t2 = s2.substr(b2, l);
        if (t1 == t2) {
            return table[test] = true;
        } else {
            sort(t1.begin(), t1.end()), sort(t2.begin(), t2.end());
            //pruning for impossible substrings
            if (t1 != t2) {
                return table[test] = false;
            }
        }
        //try each possible split
        //g|reat ? r|gtea, gr|eat ? rg|tae, gre|at ? rgt|ae ? grea|t ? rgte|a
        for (int len=1; len<l; ++len) {
            if (isScramble(s1, s2, b1, b2, len) && isScramble(s1, s2, b1+len, b2+len, l-len)) {
                return table[test] = true;
            }

            if (isScramble(s1, s2, b1, b2+l-len, len) && isScramble(s1, s2, b1+len, b2, l-len)) {
                return table[test] = true;
            }
        }

        return table[test] = false;
    }
private:
    map<SubPair, bool> table;
};

int main() {
    string s1 = "abcdefghijklmn", s2 = "efghijklmncabd";
    cout << Solution().isScramble(s1, s2) << '\n';
}