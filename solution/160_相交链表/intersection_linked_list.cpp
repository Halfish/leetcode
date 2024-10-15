#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // find length;
    ListNode *curr = headA;
    int lengthA = 0;
    while (curr) {
        lengthA++;
        curr = curr->next;
    }
    int lengthB = 0;
    curr = headB;
    while (curr) {
        lengthB++;
        curr = curr->next;
    }
    // go first
    if (lengthA > lengthB) {
        for (int i = 0; i < lengthA - lengthB; ++i) {
            headA = headA->next;
        }
    } else {
        for (int i = 0; i < lengthB - lengthA; ++i) {
            headB = headB->next;
        }
    }
    // find
    while (headA && headB) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

int main() {
    vector<int> a = {4, 1, 8, 4, 5};
    vector<int> b = {5, 6, 1, 8, 4, 5};
    ListNode *headA = new ListNode(a[0]);
    ListNode *headB = new ListNode(b[0]);
    ListNode *curr = headA;
    for (int i = 1; i < a.size(); ++i) {
        curr->next = new ListNode(a[i]);
        curr = curr->next;
    }
    curr = headB;
    for (int i = 1; i < b.size(); ++i) {
        curr->next = new ListNode(b[i]);
        curr = curr->next;
    }
    ListNode *ans = getIntersectionNode(headA, headB);
    if (ans) {
        cout << ans->val << endl;
    } else {
        cout << "null" << endl;
    }
    return 0;
}