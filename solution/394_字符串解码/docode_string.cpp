#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string decodeString(string s) {
    vector<string> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '[') {
            v.push_back(s.substr(i, 1));
        } else if (s[i] == ']') {
            string tmp = v.back();
            v.pop_back();             // pop string s
            v.pop_back();             // pop [
            int num = stoi(v.back()); // pop number
            v.pop_back();
            string str;
            for (int j = 0; j < num; ++j) {
                str += tmp;
            }
            if (v.size() > 0 && v.back()[0] >= 'a' && v.back()[0] <= 'z') {
                v[v.size() - 1] += str;
            } else {
                v.push_back(str);
            }
        } else if (s[i] >= '0' && s[i] <= '9') {
            if (v.size() > 0 && v.back()[0] >= '0' && v.back()[0] <= '9') {
                v.back().push_back(s[i]);
            } else {
                v.push_back(s.substr(i, 1));
            }
        } else {
            if (v.size() > 0 && v.back()[0] >= 'a' && v.back()[0] <= 'z') {
                v.back().push_back(s[i]);
            } else {
                v.push_back(s.substr(i, 1));
            }
        }
    }
    string ans;
    for (int i = 0; i < v.size(); ++i) {
        ans += v[i];
    }
    return ans;
}

int main() {
    cout << decodeString("3[a]2[bc]") << endl;
    cout << decodeString("3[a2[c]]") << endl;
    return 0;
}