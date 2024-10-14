#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int v) : value(v){};
};

bool hasCycle(ListNode *head) {
    // 哈希表实现
    unordered_set<ListNode *> s;
    while (head) {
        if (s.find(head->next) != s.end()) {
            return true;
        }
        s.insert(head->next);
        head = head->next;
    }
    return false;
}

bool hasCycle2(ListNode *head) {
    // 快慢指针实现
    if (!head) return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow && fast) {
        if (slow == fast) return true;
        if (!fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    vector<int> v = {3, 2, 0, -4};
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    curr->next = head;
    cout << hasCycle(head) << endl;
    cout << hasCycle2(head) << endl;
    return 0;
}