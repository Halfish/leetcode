#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums) {
    if (nums.size() == 1) {
        return 0;
    }
    if (nums[1] < nums[0]) {
        return 0;
    }
    if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
        return nums.size() - 1;
    }
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (mid == 0 || (mid > 0 && nums[mid] > nums[mid - 1])) {
            if (mid == (nums.size() - 1) ||
                (mid < (nums.size() - 1) && nums[mid] > nums[mid + 1])) {
                return mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return mid;
}

int main() {
    // vector<int> v = {1, 2, 1, 3, 5, 6, 4};
    vector<int> v = {3, 4, 3, 2, 1};
    cout << findPeakElement(v) << endl;
    return 0;
}