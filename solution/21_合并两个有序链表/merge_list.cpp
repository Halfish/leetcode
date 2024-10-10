#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        // 先记录下头结点
        ListNode *head = list1->val > list2->val ? list2 : list1;
        while (list1 && list2) {
            // 如果 L1 <= L2
            if (list1->val <= list2->val) {
                // 往前继续找小的那个 L1
                while (list1->next && list1->next->val <= list2->val) {
                    list1 = list1->next;
                }
                // L1 -> L2
                ListNode *tmp = list1->next;
                list1->next = list2;
                list1 = tmp;
            } else {
                // 如果 L1 > L2
                // 往前继续找小的那个 L2
                while (list2->next && list2->next->val < list1->val) {
                    list2 = list2->next;
                }
                // L2 -> L1
                ListNode *tmp = list2->next;
                list2->next = list1;
                list2 = tmp;
            }
        }
        return head;
    }
};

void print(ListNode *node) {
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    print(l1);
    print(l2);
    ListNode *l3 = s.mergeTwoLists(l1, l2);
    print(l3);
    return 0;
}