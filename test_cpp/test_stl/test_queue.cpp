#include <iostream>
#include <queue>
#include <deque>
using namespace std;


void test_queue() {
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(4);
    cout << "Queue size: " << q.size() << endl;
    while(!q.empty()) {
        cout << "Front: " << q.front() << ", back: " << q.back() << endl;
        q.pop();
    }
    cout << endl;
}


void test_deque() {
    deque<int> d;
    d.push_front(2);
    d.push_front(3);
    d.push_back(4);
    // 4->2->3
    for (int i = 0; i < d.size(); ++i) {
        cout << "d[" << i << "] = " << d[i] << endl;
    }
    while (!d.empty()) {
        cout << "Front: " << d.front() << ", back: " << d.back() << endl;
        d.pop_front();
    }
    cout << endl;
}

void test_priority_queue() {
    // 堆，优先队列
    int arr[4] = {2, 3, 6, 1};

    // 最大堆（默认）
    priority_queue<int> q(arr, arr+4);
    q.push(9);
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;


    // 最小堆
    priority_queue<int, vector<int>, greater<int>> q2(arr, arr+4);
    q2.push(10);
    while(!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;

}


int main() {
    cout << "Test queue:" << endl;
    test_queue();

    cout << "\nTest deque:" << endl;
    test_deque();

    cout << "\nTest priority queue:" << endl;
    test_priority_queue();
    return 0;
}
