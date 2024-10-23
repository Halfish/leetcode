#include <iostream>
#include <vector>
using namespace std;

vector<int> s2v(string s) {
    vector<int> ans;
    string tmp;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            ans.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp.push_back(s[i]);
        }
    }
    if (tmp.size() > 0) {
        ans.push_back(stoi(tmp));
    }
    return ans;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = s2v(version1);
    vector<int> v2 = s2v(version2);
    int len = v1.size() - v2.size();
    len = len > 0 ? len : -len;
    for (int i = 0; i < len; ++i) {
        if (v1.size() < v2.size()) {
            v1.push_back(0);
        } else {
            v2.push_back(0);
        }
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] < v2[i]) {
            return -1;
        } else if (v1[i] > v2[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cout << compareVersion("1.2", "1.10") << endl;
    cout << compareVersion("1.1", "1.001") << endl;
    cout << compareVersion("1.0", "1.0.0.0") << endl;
    return 0;
}