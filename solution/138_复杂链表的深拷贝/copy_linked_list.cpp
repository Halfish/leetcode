#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int v):val(v), next(nullptr), random(nullptr) {};
};

Node* copyRandomList(Node* head) {
    if (!head) {
        return nullptr;
    }
    // 1. copy
    Node* old = head;
    Node* preHead = new Node(-1);
    Node* curr = preHead;
    Node* tmp = nullptr;
    vector<Node*> oldList;
    while (old) {
        oldList.push_back(old);
        curr->next = new Node(old->val);
        curr = curr->next;
        tmp = old->next;
        old->next = curr;
        old = tmp;
    }

    // 2. random
    old = head;
    curr = preHead->next;
    for (int i = 0; i < oldList.size(); ++i) {
        if (oldList[i]->random) {
            oldList[i]->next->random = oldList[i]->random->next;
        }
    }

    for (int i = 1; i < oldList.size(); ++i) {
        oldList[i - 1]->next = oldList[i];
    }
    return preHead->next;
}

Node* build(vector<vector<int>>& v) {
    Node* preHead = new Node(-1);
    Node* curr = preHead;
    for (int i = 0; i < v.size(); ++ i) {
        curr->next = new Node(v[i][0]);
        curr = curr->next;
    }
    curr = preHead->next;
    for (int i = 0; i < v.size(); ++ i) {
        if (v[i][1] != -1) {
            int n = v[i][1];
            Node* tmp = preHead->next;
            while (n--) {
                tmp = tmp->next;
            }
            curr->random = tmp;
        }
        curr = curr->next;
    }
    return preHead->next;
}

void print_list(Node* head) {
    while(head) {
        cout << head->val << ", ";
        if (head->random) {
            cout << head->random->val;
        } else {
            cout << "null";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    vector<vector<int>> v = {{7,-1}, {13, 0}, {11, 4}, {10,2}, {1, 0}};
    Node* head = build(v);
    Node* ans = copyRandomList(head);
    print_list(ans);
    return 0;
}