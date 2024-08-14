#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int romanToInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && m[s[i + 1]] > m[s[i]]) {
            ans -= m[s[i]];
        } else {
            ans += m[s[i]];
        }
    }
    return ans;
}

int main() {
    string s = "LVIII";
    // string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}
