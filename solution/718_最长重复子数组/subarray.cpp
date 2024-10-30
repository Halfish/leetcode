#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 暴力解法
 */
int findLength(vector<int> &nums1, vector<int> &nums2) {
    int max_len = 0;
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            int len = 0;
            while (true) {
                if ((j + len) >= nums2.size() ||
                    (i + j + len) >= nums1.size()) {
                    break;
                }
                if (nums1[i + j + len] != nums2[j + len]) {
                    break;
                }
                len++;
            }
            max_len = max(max_len, len);
        }
    }
    return max_len;
}

int findLength_2(vector<int> &nums1, vector<int> &nums2) {
    int dp[nums1.size()][nums2.size()];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = nums1[i] == nums2[j] ? 1 : 0;
            } else if (nums1[i] == nums2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    nums1 = {1, 2, 3, 2, 8};
    nums2 = {5, 6, 1, 4, 7};
    cout << findLength_2(nums1, nums2) << endl;
    return 0;
}