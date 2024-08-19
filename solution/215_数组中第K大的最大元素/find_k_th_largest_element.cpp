#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


int findKthLargest(vector<int>& nums, int k) {
    // 最大堆算法，手写最大堆
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    return pq.top();
}

int findKthLargest2(vector<int>& nums, int k) {
    // 先排序, TODO(手写快排)
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

int main() {
    return 0;
}
