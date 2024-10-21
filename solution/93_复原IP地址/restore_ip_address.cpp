#include <iostream>
#include <vector>
using namespace std;

string join(vector<string> &v, string delimeter) {
    string s;
    if (v.size() == 0) {
        return s;
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        s += v[i] + delimeter;
    }
    s += v[v.size() - 1];
    return s;
}

bool is_valid(string sub) {
    if (sub.size() == 0 || sub.size() > 3) {
        return false;
    }
    int value = stoi(sub);
    if (value > 255) {
        return false;
    }
    if (sub.size() > 1 && sub[0] == '0') {
        return false;
    }
    return true;
}

void dfs(string s, vector<string> &cur, vector<string> &ans) {
    cout << "dfs " << s << ", " << join(cur, ".") << ", " << ans.size() << endl;
    if (s.length() <= 0 || cur.size() >= 4) {
        return;
    }
    if (cur.size() == 3) {
        if (!is_valid(s)) {
            return;
        }
        ans.push_back(join(cur, ".") + "." + s);
        return;
    }
    for (int i = 1; i <= 3; ++i) {
        if (i > s.size()) {
            break;
        }
        string sub = s.substr(0, i);
        if (is_valid(sub)) {
            cur.push_back(sub);
            dfs(s.substr(i), cur, ans);
            cur.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> cur;
    dfs(s, cur, ans);
    return ans;
}

void test_ip(string s) {
    vector<string> ans = restoreIpAddresses(s);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    cout << endl;
}

int main() {
    // test_ip("0000");
    test_ip("101023");
    test_ip("25525511135");
    return 0;
}
