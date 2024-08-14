#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 双指针解法，复杂度 O(N^2)
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                // 跳过连续两个一样的情况；如果包含i，已经列举过了，如果不包含
                // i，也有了；
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                // 去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    // vector<int> v = {-1, 0, 1, 2, -1, -4};
    //  vector<int> v = {-2, -1, 0, 1, 2, 3};
    //  vector<int> v = {-2, 1, 1, 1, 1};
    vector<int> v = {0, 0, 0, 0, 0};
    Solution s;
    vector<vector<int>> ans = s.threeSum(v);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}