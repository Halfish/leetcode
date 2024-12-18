#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr) {
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); ++ i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    ListNode* tail = reverseList(head);
    while(tail) {
        cout << tail->val << endl;
        tail = tail->next;
    }
    return 0;
}
