#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v) {};
};

bool isPalindrome(ListNode* head) {
    // 1. split
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
    }
    if (prev) {
        prev->next = nullptr;
    }

    // 2. reverse
    prev = nullptr;
    ListNode* next = nullptr;
    while(slow) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // 3. is pal
    if (!prev) {
        return true;
    }
    while(head && prev) {
        if (head->val != prev->val) {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}

int main() {
    // vector<int> v = {1, 2, 2, 1};
    vector<int> v = {1, 2};
    ListNode* head = new ListNode(v[0]);
    ListNode* cur = head;
    for (int i = 1; i < v.size(); ++i) {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    cout << isPalindrome(head) << endl;
    return 0;
}