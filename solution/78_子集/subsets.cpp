#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& ans) {
    if (nums.size() == 0) {
        return;
    }
    int count = ans.size();
    for (int i = 0; i < count; ++i) {
        vector<int> v(ans[i].begin(), ans[i].end());
        v.push_back(nums.back());
        ans.push_back(v);
    }
    nums.pop_back();
    dfs(nums, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    dfs(nums, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}