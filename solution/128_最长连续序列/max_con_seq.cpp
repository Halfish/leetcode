#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums) {
    int ans = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        int value = *iter;
        if (s.find(value - 1) != s.end()) {
            continue;
        }
        int max_len = 1;
        while (s.find(value + max_len) != s.end()) {
            max_len++;
        }
        ans = max(ans, max_len);
    }
    return ans;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    // nums = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums) << endl;
    return 0;
}