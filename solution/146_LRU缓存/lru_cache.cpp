#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
  public:
    Node *head;
    Node *tail;
    unordered_map<int, Node *> m;
    int capacity;
    int count;
    LRUCache(int capacity) {
        this->head = nullptr;
        this->tail = nullptr;
        this->capacity = capacity;
        this->count = 0;
    }

    void print() {
        Node *curr = this->head;
        while (curr) {
            cout << "(" << curr->key << ", " << curr->value << ") -> ";
            curr = curr->prev;
        }
        cout << endl << endl;
    }

    void update(Node *target) {
        if (this->head == target) {
            return;
        }
        if (this->tail == target) {
            this->tail = target->next;
        }
        // 删除掉原来的位置；
        if (target->prev) {
            target->prev->next = target->next;
        }
        if (target->next) {
            target->next->prev = target->prev;
        }
        // 把 target 移动到头部；
        this->head->next = target;
        target->prev = this->head;
        target->next = nullptr;
        this->head = target;
    }

    int get(int key) {
        if (this->m.find(key) == this->m.end()) {
            // 没找到直接返回
            return -1;
        }
        Node *target = this->m[key];
        this->update(target);
        return target->value;
    }

    void put(int key, int value) {
        // 查到了，需要放到头部
        if (this->m.find(key) != this->m.end()) {
            Node *target = this->m[key];
            target->value = value;
            this->update(target);
            return;
        }
        // 没查到，直接放到头部
        Node *curr = new Node(key, value);
        this->m[key] = curr;
        if (this->head) {
            this->head->next = curr;
            curr->prev = this->head;
            this->head = curr;
        } else {
            this->head = curr;
            this->tail = curr;
        }

        // 删掉尾部
        if (this->count == this->capacity) {
            this->m.erase(this->tail->key);
            Node *next = this->tail->next; // next 不可能为空
            next->prev = nullptr;
            delete this->tail;
            this->tail = next;
        } else {
            this->count++;
        }
    }
};

int main() {
    // vector<string> v = {"LRUCache", "get", "put", "get", "put", "put", "get", "get"}; 
    // vector<vector<int>> num = {{2}, {2}, {2, 6}, {1}, {1, 5}, {1, 2}, {1}, {2}};
    vector<string> v = {"LRUCache", "put", "put", "get", "put",
                        "get",      "put", "get", "get", "get"};
    vector<vector<int>> num = {{2}, {1, 1}, {2, 2}, {1}, {3, 3},
                               {2}, {4, 4}, {1},    {3}, {4}};
    LRUCache *lru = new LRUCache(num[0][0]);
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == "put") {
            lru->put(num[i][0], num[i][1]);
            cout << "Put " << num[i][0] << ", " << num[i][1] << endl;
        } else if (v[i] == "get") {
            int value = lru->get(num[i][0]);
            cout << "Get " << num[i][0] << " -> " << value << endl;
        }
        // lru->print();
    }
    Node *curr = lru->head;
    while (curr) {
        Node *tmp = curr;
        curr = curr->prev;
        delete tmp;
    }
    delete lru;
    return 0;
}
