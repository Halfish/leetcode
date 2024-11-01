#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

int main() {
    vector<int> v = {3, 4, 5, 1, 2};
    cout << findMin(v) << endl;
    return 0;
}