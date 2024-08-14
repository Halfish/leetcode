#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() == 0) {
            int size = nums2.size();
            if (size % 2 == 0) {
                return (nums2[size / 2 - 1] + nums2[size / 2]) / 2;
            }
            return nums2[size / 2];
        }
        if (nums2.size() == 0) {
            int size = nums1.size();
            if (size % 2 == 0) {
                return (nums1[size / 2 - 1] + nums1[size / 2]) / 2;
            }
            return nums1[size / 2];
        }

        int total = nums1.size() + nums2.size();
        int index = total / 2;

        int i = 0;
        int j = 0;
        // 奇数
        if (total % 2 == 1) {
            int ans = 0;
            while (i + j <= index) {
                if (i >= nums1.size() ||
                    (j < nums2.size() && nums1[i] > nums2[j])) {
                    ans = nums2[j];
                    j++;
                } else {
                    ans = nums1[i];
                    i++;
                }
            }
            return ans;
        }

        // 偶数
        int ans1 = 0;
        int ans2 = 0;
        while (i + j <= index) {
            ans1 = ans2;
            if (i >= nums1.size() ||
                (j < nums2.size() && nums1[i] > nums2[j])) {
                ans2 = nums2[j];
                j++;
            } else {
                ans2 = nums1[i];
                i++;
            }
        }
        return (ans1 + ans2) / 2.0;
    }
};

int main() {
    Solution s;
    vector<int> v2 = {3, 4, 5, 6};
    vector<int> v1 = {2, 3};
    double result = s.findMedianSortedArrays(v1, v2);
    cout << "result is " << result << endl;
    return 0;
}