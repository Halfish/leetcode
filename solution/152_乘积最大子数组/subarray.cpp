#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int max(int a, int b, int c) {
    return max(a, max(b, c));
}
int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int maxProduct(vector<int>& nums) {
    int len = nums.size();
    int dp_min[len];
    int dp_max[len];
    memset(dp_min, 0, sizeof(dp_min));
    memset(dp_max, 0, sizeof(dp_max));
    int ans = INT_MIN;
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    for (int i = 1; i < len; ++i) {
        dp_min[i] = min(nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]);
        dp_max[i] = max(nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]);
        ans = max(ans, dp_max[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;
    return 0;
}
