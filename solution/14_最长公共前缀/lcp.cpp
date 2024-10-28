#include <iostream>
#include <vector>
using namespace std;

int getLen(vector<string> &strs) {
    int len = 0;
    for (len = 0; len < strs[0].size(); ++len) {
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].size() <= len || strs[0][len] != strs[i][len]) {
                return len;
            }
        }
    }
    return len;
}

string longestCommonPrefix(vector<string> &strs) {
    int len = getLen(strs);
    return strs[0].substr(0, len);
}

int main() {
    vector<string> v = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(v) << endl;
    return 0;
}