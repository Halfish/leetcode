#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[index]);
            index++;
        }
    }
}

int main() {
    vector<int> v = {0, 1, 0, 3, 12};
    moveZeroes(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}