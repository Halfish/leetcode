#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums) {
    while (true) {
        int index = rand() % nums.size();
        int cand = nums[index];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == cand) {
                count++;
            }
        }
        if (count * 2 >= nums.size()) {
            return cand;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(v) << endl;
    return 0;
}