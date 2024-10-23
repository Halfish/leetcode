#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v) {};
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 1. make sure l1 < l2
    int len1 = 0;
    int len2 = 0;
    ListNode* node = l1;
    while (node) {
        len1++;
        node = node->next;
    }
    node = l2;
    while (node) {
        len2++;
        node = node->next;
    }
    if (len1 > len2) {
        swap(l1, l2);
    }

    // 2. add
    int reminder = 0;
    ListNode* prev = nullptr;
    node = l2;
    while (node) {
        node->val = node->val + reminder;
        if (l1) {
            node->val += l1->val;
            l1 = l1->next;
        }
        reminder = node->val / 10;
        node->val = node->val % 10;
        prev = node;
        node = node->next;
    }
    if (reminder > 0) {
        prev->next = new ListNode(reminder);
    }
    return l2;
}

ListNode* construct(vector<int>& v) {
    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

void print_list(ListNode* node) {
    while(node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {9,9,9,9,9,9,9};
    vector<int> v2 = {9,9,9,9};
    ListNode* l1 = construct(v1);
    ListNode* l2 = construct(v2);
    ListNode* l3 = addTwoNumbers(l1, l2);
    print_list(l3);
    return 0;
}