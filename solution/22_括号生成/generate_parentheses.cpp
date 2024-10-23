#include <iostream>
#include <vector>
using namespace std;

void dfs(int left, int right, string &cur, vector<string> &ans) {
    if (right == 0) {
        ans.push_back(cur);
        return;
    }
    if (left > 0) {
        cur.push_back('(');
        dfs(left - 1, right, cur, ans);
        cur.pop_back();
    }
    if (left < right) {
        cur.push_back(')');
        dfs(left, right - 1, cur, ans);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string cur;
    dfs(n, n, cur, ans);
    return ans;
}

int main() {
    vector<string> ans = generateParenthesis(3);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}