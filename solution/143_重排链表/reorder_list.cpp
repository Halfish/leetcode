#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};

ListNode* reverseList(ListNode* node) {
    ListNode* prev = nullptr;
    ListNode* tmp = nullptr;
    while (node) {
        tmp = node->next;
        node->next = prev;
        prev = node;
        node = tmp;
    }
    return prev;
}

void mergeList(ListNode* node1, ListNode* node2) {
    ListNode* tmp = nullptr;
    while(node1) {
        tmp = node1->next;
        node1->next = node2;
        node1 = node2;
        node2 = tmp;
    }
}

void reorderList(ListNode *head) {
    // 1. 分割链表
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // 2. 翻转链表
    ListNode* second = reverseList(slow);

    // 3. 合并链表
    mergeList(head, second);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    reorderList(head);
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}