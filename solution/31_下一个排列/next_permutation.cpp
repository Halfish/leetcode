
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1) {
        return;
    }
    // 1. find nums[i] < nums[i + 1]
    int i;
    for (i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }

    if (i >= 0) {
        // 2. find nums[k] > nums[i]
        int k;
        for (k = nums.size() - 1; k > i; --k) {
            if (nums[k] > nums[i]) {
                break;
            }
        }
        // 3. swap nums[i], nums[k]
        swap(nums[i], nums[k]);
    }
    // 4. reverse
    int left = i + 1;
    int right = nums.size() - 1;
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    nums = {6, 5, 4, 3, 2, 1};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}