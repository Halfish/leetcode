#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s) {
    vector<string> arr;
    int begin = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != ' ' && s[i - 1] == ' ') {
            begin = i;
        }
        if (s[i] == ' ' && s[i - 1] != ' ') {
            arr.push_back(s.substr(begin, i - begin));
        }
    }
    if (s[s.size() - 1] != ' ') {
        arr.push_back(s.substr(begin, s.size() - begin));
    }
    string ans = arr.size() > 0 ? arr[arr.size() - 1]: "";
    for (int i = arr.size() - 2; i >= 0; --i) {
        ans += " " + arr[i];
    }
    return ans;
}

int main() {
    cout << reverseWords("the sky is blue") << endl;
    cout << reverseWords("  hello world  ") << endl;
    return 0;
}