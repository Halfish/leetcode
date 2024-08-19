#include <iostream>
#include <stack>
using namespace std;


void test_stack() {
    //stack<int> s = {3, 4, 2};
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(2);

    cout << "Size: " << s.size() << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    s.emplace(10);
    cout << "Top: " << s.top() << endl;
}

int main() {
    test_stack();
    return 0;
}
