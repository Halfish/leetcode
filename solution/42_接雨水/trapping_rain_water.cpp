#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height) {
    if (height.size() <= 2) {
        return 0;
    }
    int ans = 0;
    int left = 0;
    int right = height.size() - 1;
    int maxLeft = height[left];
    int maxRight = height[right];
    while (left <= right) {
        if (maxLeft <= maxRight) {
            maxLeft = max(maxLeft, height[left]);
            ans += maxLeft - height[left];
            left++;
        } else {
            maxRight = max(maxRight, height[right]);
            ans += maxRight - height[right];
            right--;
        }
    }
    return ans;
}

int main() {
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> height = {4, 2, 0, 3, 2, 5};
    vector<int> height = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    cout << trap(height) << endl;
    return 0;
}