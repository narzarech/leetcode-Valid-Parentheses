#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
using namespace std;
class Solution {
private:
    map<char, char>bracket = { { '(', ')' } , { '{', '}' } , { '[' , ']' } };
    bool process(char c, stringstream& ss) {
        bool b = 1;
        char tmp; ss >> tmp;
        //({
        if (bracket.find(tmp) != bracket.end()) {
            b = process(tmp, ss);
            if (b == 0) {
                return b;
            }
        }
        //(]
        else if (tmp != bracket.find(c)->second) {
            return 0;
        }
        //()
        else {
            return 1;
        }
        return process(c, ss);
    }
public:
    bool isValid(string s) {
        bool cond = 1;
        stringstream ss(s);
        char c;
        while (ss >> c) {
            cond = process(c, ss);
            if (cond == 0) {
                return 0;
            }
        }
        return cond;
    }
};
int main() {
    string s; cin >> s;
    Solution sol;
    cout << sol.isValid(s);
}