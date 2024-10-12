#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int v) : value(v){};
};

ListNode *reverse(ListNode *head, ListNode *tail) {
    ListNode* node = head;
    cout << "reverse: ";
    for (ListNode* node = head; node != tail; node = node->next) {
        cout << node->value << " ";
    }
    cout << endl;
    // return new Head
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != tail) {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *curr = head;
    ListNode *last = nullptr;   // 记录上一个链表尾
    ListNode *ret = nullptr;    // 记录整个链表的头
    while (true) {
        // 1. 找到子链表
        ListNode *start = curr;
        bool shouldBreak = false;
        for (int i = 0; i < k; ++i) {
            if (!curr) {
                shouldBreak = true;
                break;
            }
            curr = curr->next;
        }
        if (shouldBreak) {
            // 不够 k 个数，不用翻转
            last->next = start;
            break;
        }
        // 翻转子链表
        ListNode *newHead = reverse(start, curr);
        if (!ret) {
            ret = newHead; // 只赋值一次
        }
        if (last) {
            // 连接上一个子链表
            last->next = newHead;
        }
        last = start;
    }
    return ret ? ret : head;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(v[0]);
    ListNode *curr = head;
    for (int i = 1; i < v.size(); ++i) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    ListNode *newHead = reverseKGroup(head, 1);
    while (newHead) {
        cout << newHead->value << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}