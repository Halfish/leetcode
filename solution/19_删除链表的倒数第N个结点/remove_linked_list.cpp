#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v) {};
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    // find node
    ListNode* first = head;
    for (int i = 0; i < n; ++i) {
        if (!first) {
            return head;
        }
        first = first->next;
    }

    ListNode* second = head;
    ListNode* prev = nullptr;
    while(first) {
        first = first->next;
        prev = second;
        second = second->next;
    }

    // delete node
    if (prev) {
        prev->next = second->next;
        delete second;
        return head;
    }
    second = head->next;
    delete(head);
    return second;
}


void test() {
    //vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v = {1, 2};
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    ListNode* newHead = removeNthFromEnd(head, 2);
    while(newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
}

int main() {
    test();
    return 0;
}
