#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v){};
    ListNode(int v, ListNode *n) : val(v), next(n){};
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // preHead 技巧很重要
        ListNode *preHead = new ListNode(-1);
        // curr 会沿着合并后的链表移动
        ListNode *curr = preHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        // 别忘了最后一个结点
        curr->next = l1 ? l1 : l2;
        return preHead->next;
    }
};

ListNode *setup(int arr[], int size) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < size; ++i) {
        curr->next = new ListNode(arr[i]);
    }
    return head;
}

void print(ListNode *node) {
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 3, 4, 6};
    int arr2[] = {5, 7, 8};
    ListNode *l1 = setup(arr1, sizeof(arr1) / sizeof(int));
    ListNode *l2 = setup(arr2, sizeof(arr2) / sizeof(int));
    print(l1);
    print(l2);
    Solution s;
    ListNode *l3 = s.mergeList(l1, l2);
    print(l3);
    return 0;
}