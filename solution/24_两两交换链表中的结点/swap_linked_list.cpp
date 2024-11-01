#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};

ListNode *swapPairs(ListNode *head) {
    if (!head) {
        return head;
    }
    ListNode *preHead = new ListNode(-1);
    preHead->next = head;

    ListNode *last = preHead;   // 上一个链表对的结尾
    ListNode *prev = head;
    ListNode *curr = nullptr;

    while (prev && prev->next) {
        curr = prev->next;
        ListNode *tmp = curr->next;

        // 重新连接； last->prev->curr->tmp 改成 last->curr->prev->tmp
        curr->next = prev;
        prev->next = tmp;
        last->next = curr;

        last = prev;
        prev = tmp;
    }
    return preHead->next;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    // v = {1, 3, 2};
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    curr = swapPairs(head);
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}