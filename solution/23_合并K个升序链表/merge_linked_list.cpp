#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};

struct Compare {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ans = nullptr;
    ListNode *curr = nullptr;
    // 最小堆
    priority_queue<ListNode *, vector<ListNode *>, Compare> q;
    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i]) {
            q.push(lists[i]);
        }
    }
    while (!q.empty()) {
        ListNode *top = q.top();
        q.pop();
        if (!ans) {
            ans = top;
            curr = top;
        } else {
            curr->next = top;
            curr = top;
        }
        if (top->next) {
            q.push(top->next);
        }
    }
    return ans;
}

vector<ListNode *> initData() {
    vector<vector<int>> data = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    std::vector<ListNode *> lists;
    for (vector<int> &arr : data) {
        if (arr.size() == 0) {
            continue;
        }
        ListNode *head = new ListNode(arr[0]);
        ListNode *curr = head;
        for (int i = 1; i < arr.size(); ++i) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        lists.push_back(head);
    }
    return lists;
}

int main() {
    vector<ListNode *> lists = initData();
    ListNode *ans = mergeKLists(lists);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}