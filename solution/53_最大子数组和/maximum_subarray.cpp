#include <iostream>
#include <vector>
using namespace std;


/*
 * 动态规划求解
 */
int maxSubArray(vector<int> &nums) {
    int dp = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        // dp[i] = max(0, dp[i-1]) + nums[i];
        dp = max(0, dp) + nums[i];
        ans = max(ans, dp);
    }
    return ans;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(nums);
    cout << "result: " << result << endl;
    return 0;
}
