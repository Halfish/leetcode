#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool isValid(string s) {
    stack<char> my_s;
    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            my_s.push(c);
            continue;
        } 
        if (my_s.empty()) return false;
        char top = my_s.top();
        if (c == ']' && top != '[') return false;
        if (c == ')' && top != '(') return false;
        if (c == '}' && top != '{') return false;
        my_s.pop();
    }
    return my_s.empty();
}


int main() {
    cout << isValid("{[]}") << endl;
    cout << isValid("{[]") << endl;
    return 0;
}