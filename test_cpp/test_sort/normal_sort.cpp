
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


/*
 * 冒泡排序
 */
void bubble_sort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
}

/*
 * 堆排序
 */
void heap_sort(vector<int> &v) {
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    v.swap(res);
}

int main() {
    vector<int> v = {2, 3, 1, 5, 12, 3, 21};
    // bubble_sort(v);
    heap_sort(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}