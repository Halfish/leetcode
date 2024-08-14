#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> original_nums(nums);

        // 1. Find Answer
        sort(nums.begin(), nums.end());
        int index = -1;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (findNumber(nums, i + 1, nums.size() - 1, target - nums[i]) >
                0) {
                index = i;
                break;
            }
        }
        // 2. Find original index
        vector<int> ans;
        if (index >= 0) {
            for (size_t i = 0; i < original_nums.size(); ++i) {
                if (original_nums[i] == nums[index]) {
                    ans.push_back(i);
                    continue;
                }
                if (original_nums[i] == target - nums[index]) {
                    ans.push_back(i);
                }
                if (ans.size() >= 2) {
                    break;
                }
            }
        }
        return ans;
    }

    // 二分法，返回 index
    int findNumber(vector<int> &nums, int begin, int end, int number) {
        if (begin < 0 || end >= nums.size() || begin > end) {
            return -1;
        }
        if (begin == end) {
            return nums[begin];
        }
        int middle = (begin + end) / 2;
        if (nums[middle] == number) {
            return middle;
        } else if (nums[middle] > number) {
            return findNumber(nums, begin, middle - 1, number);
        }
        return findNumber(nums, middle + 1, end, number);
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
