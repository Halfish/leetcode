#include <queue>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;


int findKthLargest1(vector<int>& nums, int k) {
    // 最大堆算法，手写最大堆
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    return pq.top();
}

int findKthLargest2(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

void print(vector<int>& nums, int start, int end) {
    for (int i = start; i <= end; ++ i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}



void quick_sort(vector<int>& nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = nums[end];
    int i = 0;
    int j = end - 1;
    while (i < j) {
        if (nums[i] <= pivot) {
            i ++;
            continue;
        }
        if (nums[j] > pivot) {
            j --;
            continue;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    if (nums[i] > pivot) {
        nums[end] = nums[i];
        nums[i] = pivot;
    }

    cout << start << ", " << end << ", " << pivot << endl;
    print(nums, start, end);

    quick_sort(nums, start, i - 1);
    quick_sort(nums, i + 1, end);
}



void test_quick_sort() {
    //vector<int> nums = {3, 2, 1, 5, 6, 4};
    vector<int> nums = {6, 2, 5, 4, 3, 1};
    //shuffle(nums.begin(), nums.end(), default_random_engine(random_device()()));
    quick_sort(nums, 0, nums.size() - 1);
}


int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    // cout << findKthLargest1(nums, 3) << endl;
    //cout << findKthLargest2(nums, 3) << endl;
    //cout << find_with_quick_sort(nums, 3) << endl;
    test_quick_sort();
    return 0;
}
