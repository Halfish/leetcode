#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    // 去掉负数
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            nums[i] = 0;
        }
    }
    int i = 0;
    while(i < nums.size()) {
        if (nums[i] > nums.size() || nums[i] <= 0) {
            i++;
            continue;
        }
        // 标记 nums[target] = -1，表示这个位置的数字出现了。
        int target = nums[i] - 1;
        if (nums[target] >= 0) {
            nums[i] = -1;
            swap(nums[i], nums[target]);
        } else {
            i++;
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] >= 0) {
            // 第一个不为负数的，就是答案
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main() {
    //vector<int> v = {1, 2, 0};
    //vector<int> v = {3, 4, -1, 1};
    vector<int> v = {1, 1};
    cout << firstMissingPositive(v) << endl;
    return 0;
}