#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int rob(vector<int>& nums) {
    int dp[nums.size()];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        dp[i] = nums[i];
        if (i == 2) {
            dp[i] += nums[0];
        } else if (i > 2) {
            dp[i] += max(dp[i - 2], dp[i - 3]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    //vector<int> v = {1,2,3,1};
    vector<int> v = {2,7,9,3,1};
    cout << rob(v) << endl;
    return 0;
}
