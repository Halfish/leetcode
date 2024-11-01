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
    ListNode *newHead = nullptr;

    ListNode *last = nullptr;
    ListNode *prev = head;
    ListNode *curr = nullptr;

    while (prev) {
        curr = prev->next;
        if (!curr) {
            break;
        }
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev->next = tmp;
        if (!last) {
            newHead = curr;
        } else {
            last->next = curr;
        }
        last = prev;
        prev = tmp;
    }
    return newHead ? newHead : head;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    v = {1, 3, 2};
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