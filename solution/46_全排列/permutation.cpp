#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& v, queue<int>& q) {
    if (q.empty()) {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < q.size(); ++ i) {
        int top = q.front();
        v.push_back(top);
        q.pop();
        dfs(ans, v, q);
        q.push(top);
        v.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    queue<int> q;
    for (int n : nums) {
        q.push(n);
    }
    nums.clear();
    dfs(ans, nums, q);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}