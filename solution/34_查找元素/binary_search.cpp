#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &nums, int target, bool for_start) {
    int ans = -1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (for_start) {
                ans = mid;
                right = mid - 1;
            } else {
                ans = mid;
                left = mid + 1;
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int begin = binary_search(nums, target, true);
    int end = binary_search(nums, target, false);
    return {begin, end};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(nums, 7);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}