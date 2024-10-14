#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = nums1.size() - 1;
    while (j >= 0) {
        if (i < 0 || nums1[i] <= nums2[j]) {
            nums1[k] = nums2[j];
            j --;
        } else {
            nums1[k] = nums1[i];
            i --;
        }
        k --;
    }
}

int main() {
    vector<int> nums1 = {0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 0, nums2, 3);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}