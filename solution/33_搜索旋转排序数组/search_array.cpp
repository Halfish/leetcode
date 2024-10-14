#include <iostream>
#include <vector>
using namespace std;


int search(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int pivot = nums[0];
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        // cout << "left " << left << ", right " << right << endl;
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            if (nums[mid] >= pivot && nums[left] > target) {
                // 有个例外，往左走，走到最左边还没找到，其实在右边，即 [mid + 1, right]
                left = mid + 1;
            } else {
                // 按照正常逻辑应该在左边，即 [left, mid - 1]
                right = mid - 1;
            }
        } else {
            if (nums[mid] < pivot && nums[right] < target) {
                // 有个例外，往右走，走到最右边还没找到，其实在左边，即 [left, mid - 1]
                right = mid - 1;
            } else {
                // 按照正常二分查找的逻辑，在右边，即 [mid + 1, right]
                left = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    // vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> v = {1, 3, 5};
    vector<int> v = {4, 5, 6, 7, 8, 1, 2, 3};
    cout << search(v, 8) << endl;
    return 0;
}