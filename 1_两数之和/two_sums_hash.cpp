#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++ i) {
            if (s.find(target - nums[i]) != s.end()) {
                for (int j = 0; j < nums.size(); ++ j) {
                    if (i == j) {
                        continue;
                    }
                    if (nums[j] == target - nums[i]) {
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    vector<int> ans = s.twoSum(nums, 6);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
