#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};

ListNode *deleteDuplicates(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr && curr->next) {
        if (curr->val != curr->next->val) {
            prev = curr;
            curr = curr->next;
            continue;
        }
        // find all nodes
        ListNode *end = curr->next;
        while (end && curr->val == end->val) {
            ListNode* next = end->next;
            delete end;
            end = next;
        }
        if (curr == head) {
            head = end;
        }
        delete curr;
        if (prev) {
            prev->next = end;
        }
        curr = end;
    }
    return head;
}

void test(vector<int> &v) {
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    ListNode *node = deleteDuplicates(head);
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 3, 4, 4, 5};
    //vector<int> v = {1, 1, 1, 1, 4, 5};
    test(v);
    return 0;
}