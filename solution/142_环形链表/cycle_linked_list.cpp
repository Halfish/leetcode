#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v) {};
};

ListNode *detectCycle(ListNode *head) {
    // 快慢指针第一次相遇
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (!fast) {
            return nullptr;
        }
        fast = fast->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast) {
        return nullptr;
    }
    // ans 和 slow 必相遇与环的头节点
    ListNode* ans = head;
    while (ans != slow) {
        ans = ans->next;
        slow = slow->next;
    }
    return ans;
}

int main() {
    // list
    vector<int> v = {3,2, 0, -4};
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    // cycle
    int pos = 1;
    ListNode* target = head;
    while (pos--) {
        target = target->next;
    }
    curr->next = target;

    ListNode* ans = detectCycle(head);
    if (ans) {
        cout << ans->val << endl;
    } else {
        cout << "null" << endl;
    }
    return 0;
}