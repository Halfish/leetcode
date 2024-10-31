#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int ans = 0;
    int i = 0;
    int j = 0;
    int sum = nums[0];
    while (i < nums.size() && j < nums.size()) {
        if (sum < target) {
            j++;
            if (j < nums.size()) {
                sum += nums[j];
            } else {
                break;
            }
        } else if (sum >= target) {
            if (ans == 0) {
                ans = j - i + 1;
            } else {
                ans = min(ans, j - i + 1);
            }
            sum -= nums[i];
            i++;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {1, 4, 4};
    cout << minSubArrayLen(4, v) << endl;

    v = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(11, v) << endl;
    return 0;
}