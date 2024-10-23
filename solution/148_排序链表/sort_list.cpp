#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
};


void print_list(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* findMid(ListNode* head) {
    ListNode* mid = head;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            mid = slow;
            slow = slow->next;
        }
    }
    // cut mid
    if (mid) {
        ListNode* tmp = mid->next;
        mid->next = nullptr;
        mid = tmp;
    }
    return mid;
}

/*
 * 合并了两个有序链表
 */
ListNode* merge(ListNode* first, ListNode* second) {
    if (!first) {
        return second;
    }
    if (!second) {
        return first;
    }
    ListNode* preHead = new ListNode(-1);
    ListNode* curr = preHead;
    while (first && second) {
        if (first->val > second->val) {
            curr->next = second;
            second = second->next;
        } else {
            curr->next = first;
            first = first->next;
        }
        curr = curr->next;
    }
    curr->next = first ? first : second;
    return preHead->next;
}

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* mid = findMid(head);
    head = sortList(head);
    mid = sortList(mid);
    return merge(head, mid);
}

int main() {
    //vector<int> v = {4, 2, 1, 3};
    vector<int> v = {-1, 5, 3, 4, 0};
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    head = sortList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}