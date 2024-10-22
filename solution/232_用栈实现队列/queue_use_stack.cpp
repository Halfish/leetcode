#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MyQueue {
  private:
    stack<int> pop_stack;
    stack<int> push_stack;

  public:
    MyQueue() {}

    void push(int x) {
        while (!pop_stack.empty()) {
            int top = pop_stack.top();
            push_stack.push(top);
            pop_stack.pop();
        }
        push_stack.push(x);
    }

    int pop() {
        int top = this->peek();
        pop_stack.pop();
        return top;
    }

    int peek() {
        while (!push_stack.empty()) {
            int top = push_stack.top();
            pop_stack.push(top);
            push_stack.pop();
        }
        return pop_stack.top();
    }

    bool empty() { return push_stack.empty() && pop_stack.empty(); }
};

void test_queue() {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
}

int main() {
    test_queue();
    return 0;
}