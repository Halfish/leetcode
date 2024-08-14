#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    // ["flower", "flow", "flight"]
    if (strs.empty()) {
        return "";
    }
    if (strs.size() == 1) {
        return strs[0];
    }
    int len = 0;
    bool shouldBreak = false;
    while (true) {
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].length() <= len || strs[0].length() <= len) {
                shouldBreak = true;
            }
            if (strs[i][len] != strs[0][len]) {
                shouldBreak = true;
            }
            if (shouldBreak) {
                return strs[0].substr(0, len);
            }
        }
        len++;
    }
}

int main() {
    vector<string> v;
    v.push_back("flow");
    v.push_back("fec");
    // v.push_back("flower");
    // v.push_back("flight");
    cout << longestCommonPrefix(v) << endl;
    return 0;
}
