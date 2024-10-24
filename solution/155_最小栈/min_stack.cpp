#include <iostream>
#include <vector>
using namespace std;

class MinStack {
  private:
    vector<int> value;
    vector<int> min_value;

  public:
    MinStack() {}

    void push(int val) {
        value.push_back(val);
        if (min_value.empty()) {
            min_value.push_back(val);
        } else {
            min_value.push_back(min(min_value.back(), val));
        }
    }

    void pop() {
        value.pop_back();
        min_value.pop_back();
    }

    int top() { return value.back(); }

    int getMin() { return min_value.back(); }
};

int main() {

    MinStack *obj = new MinStack();
    obj->push(3);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << " " << param_4 << endl;
    return 0;
}