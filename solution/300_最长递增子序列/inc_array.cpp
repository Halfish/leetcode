#include <iostream>
#include <vector>
using namespace std;

/*
 * dp
 */
int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < dp.size(); ++i) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int binary_search(vector<int> &d, int target) {
    int left = 0;
    int right = d.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (d[mid] == target) {
            return mid;
        } else if (d[mid] > target) {
            // 找到 i, 满足 d[i] < target < d[i + 1]
            if (mid > 0 && d[mid - 1] < target || mid == 0) {
                return mid;
            } else {
                right = mid - 1;
            }
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

/*
 * greedy + binary_search
 */
int greedy(vector<int> &nums) {
    vector<int> d;
    for (int i = 0; i < nums.size(); ++i) {
        if (d.size() == 0 || d[d.size() - 1] < nums[i]) {
            d.push_back(nums[i]);
        } else {
            int index = binary_search(d, nums[i]);
            d[index] = nums[i];
        }
    }
    return d.size();
}

int main() {
    // vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> v = {7, 7, 7, 7, 7, 7};
    vector<int> v = {0, 1, 0, 3, 2, 3};
    cout << lengthOfLIS(v) << endl;
    cout << greedy(v) << endl;
    return 0;
}
