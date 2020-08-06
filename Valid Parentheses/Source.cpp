#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
private:
    unordered_map<char, char>bracket = { { '(', ')' } , { '{', '}' } , { '[' , ']' } };
public:
    bool isValid(string s) {
        stringstream ss(s);
        char c;
        stack<char>opbracket;
        while (ss >> c) {
            //if opening bracket
            if (bracket.find(c) != bracket.end()) {
                opbracket.push(c);
            }
            //if closing bracket
            else {
                if (opbracket.size() == 0) {
                    return 0;
                }
                if (c == bracket.find(opbracket.top())->second) {
                    opbracket.pop();
                }
                else {
                    return 0;
                }
            }
        }
        if (opbracket.size() == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
};
int main() {
    string s; cin >> s;
    Solution sol;
    cout << sol.isValid(s);
}