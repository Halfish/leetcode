#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        ListNode *next = curr->next;
        if (next && curr->val == next->val) {
            ListNode *tmp = next->next;
            delete next;
            curr->next = tmp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    vector<int> v = {1, 1, 2, 3, 3};
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    curr = deleteDuplicates(head);
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
