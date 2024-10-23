#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; ++i) {
        pq.push(make_pair(nums[i], i));
    }

    vector<int> ans;
    ans.push_back(pq.top().first);
    for (int i = k; i < nums.size(); ++i) {
        pq.push(make_pair(nums[i], i));
        while (true) {
            pair<int, int> top = pq.top();
            // 把下标超过滑动窗口的元素全丢弃掉
            if (top.second <= i - k) {
                pq.pop();
            } else {
                break;
            }
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}

int main() {
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxSlidingWindow(v, 3);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}