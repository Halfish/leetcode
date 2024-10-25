#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &candidates, vector<int> &curr, int target,
         vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(vector<int>(curr));
    }
    for (int i = 0; i < candidates.size(); ++i) {
        if (curr.size() > 0 && candidates[i] > curr[curr.size() - 1]) {
            continue;
        }
        if (candidates[i] <= target) {
            curr.push_back(candidates[i]);
            dfs(candidates, curr, target - candidates[i], ans);
            curr.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    dfs(candidates, curr, target, ans);
    return ans;
}

int main() {
    vector<int> cand = {8, 7, 4, 3};
    vector<vector<int>> ans = combinationSum(cand, 11);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}