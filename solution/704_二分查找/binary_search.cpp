#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {-1, 0, 3, 5, 9, 12};
    cout << search(v, 9) << endl;
    return 0;
}