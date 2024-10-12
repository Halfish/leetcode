#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode() { value = 0;};
    ListNode(int v): value(v) {};
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    // 1. record bridge
    for (int i = 1; i < left; ++i) {
        prev = curr;
        curr = curr->next;
    }
    ListNode* bridge = prev;        // 要反转的链表之前的结点
    ListNode* sub_start = curr;     // 要反转的链表的开始

    // 2. reverse
    for (int i = left; i <= right; ++i) {
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    // 此时 prev 是要翻转的链表的尾部，curr 是下一个结点

    // 3. link
    if (sub_start) {
        // 连接尾部
        sub_start->next = curr;
    }
    if (bridge) {
        // 连接开头
        bridge->next = prev;
        return head;
    }
    // 没有开头则 prev 就是新的开头
    return prev;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); ++ i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    ListNode* newHead = reverseBetween(head, 3, 4);
    while (newHead) {
        cout << newHead->value << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
