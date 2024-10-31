#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * 暴力解法，O(N^2)，超时
 */
int subarraySum(vector<int> &nums, int k) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int sum = 0;
        int len = 0;
        while ((len + i) < nums.size()) {
            sum += nums[i + len];
            len++;
            if (sum == k) {
                ans++;
            }
        }
    }
    return ans;
}

/*
 * 动态规划，超时！
 */
int subarraySum_2(vector<int> &nums, int k) { return 0; }

/*
 * 题解：前缀和 + 哈希表
 */
int subarraySum_3(vector<int> &nums, int k) {
    int ans = 0;
    unordered_map<int, int> m;
    vector<int> v(nums.size(), 0);
    int sum = 0;
    m[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        v[i] = sum;
        if (m.find(v[i] - k) != m.end()) {
            ans += m[v[i] - k];
        }
        m[v[i]] ++;
    }
    return ans;
}

int main() {
    vector<int> v = {1, -1, 0};
    cout << subarraySum_3(v, 0) << endl;
    return 0;
}