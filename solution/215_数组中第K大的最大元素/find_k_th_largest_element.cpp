#include <queue>
#include <algorithm>
#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;


int findKthLargest1(vector<int>& nums, int k) {
    // 最大堆算法，手写最大堆
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
        pq.pop();
    }
    return pq.top();
}

// 维护一个大小为 K 的最小堆
int findKthLargest2(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); ++i) {
        if (pq.size() < k) {
            pq.push(nums[i]);
        } else if (pq.top() < nums[i]) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int findKthLargest3(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

/*
 * 基于快排的算法
 */
int find_k_th_largest(vector<int>& nums, int start, int end, int k) {
    cout << "Find k = " << k << ", start = " << start << ", end = " << end << " in array [";
    for (int i = start; i <= end; ++ i) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    if (start == end) {
        return nums[k];
    }

    int index = rand() % (end - start) + start;
    swap(nums, end, index);
    int pivot = nums[end];
    int i = start;
    int j = end;
    while (i < j) {
        if (nums[i] <= pivot) {
            i ++;
            continue;
        }
        if (nums[j] >= pivot) {
            j --;
            continue;
        }
        swap(nums, i, j);
    }
    swap(nums, i, end);
    if (i == k) {
        return nums[k];
    } else if (i < k) {
        return find_k_th_largest(nums, i + 1, end, k);
    }
    return find_k_th_largest(nums, start, i - 1 , k);
}

/*
 * 官方题解
 */
int quickselect(vector<int> &nums, int l, int r, int k) {
    if (l == r)
        return nums[k];
    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (nums[i] < partition);
        do j--; while (nums[j] > partition);
        if (i < j)
            swap(nums[i], nums[j]);
    }
    if (k <= j)return quickselect(nums, l, j, k);
    else return quickselect(nums, j + 1, r, k);
}


int main() {
    //vector<int> nums = {3, 2, 1, 5, 6, 4};
    //vector<int> nums = {2, 3, 5, 3, 4, 2, 1, 8, 9, 7};
    //vector<int> nums = {5,2,4,1,3,6,0};
    vector<int> nums = {
        1,2,3,4,5,1,1,1,1,1,1,1,1,-5,-4,-3,-2,-1
    };
    int k = 4;
    cout << findKthLargest1(nums, k) << endl;
    cout << findKthLargest2(nums, k) << endl;
    cout << findKthLargest3(nums, k) << endl;
    cout << find_k_th_largest(nums, 0, nums.size() - 1, nums.size() - k) << endl;
    cout << quickselect(nums, 0, nums.size() - 1, nums.size() - k) << endl;
    return 0;
}
