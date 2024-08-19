#include <iostream>
#include <list>
#include <forward_list>
using namespace std;


void print(list<int>& l) {
    for (list<int>::iterator iter = l.begin(); iter != l.end(); ++iter) {
        cout << *iter << " <=> ";
    }
    cout << endl;
}

void test_list() {
    list<int> l;
    l.push_front(3);
    l.push_front(7);
    l.push_back(4);
    // 4 <=> 3 <=> 7
    print(l);

    l.insert(++l.begin(), 10);
    print(l);
}


void print_fl(forward_list<int>& fl) {
    for (forward_list<int>::iterator iter = fl.begin(); iter != fl.end(); ++iter) {
        cout << *iter << " -> ";
    }
    cout << endl;
}


void test_forward_list() {
    forward_list<int> fl;
    fl.push_front(3);
    fl.push_front(7);
    fl.push_front(10);
    // 10 -> 7 -> 3
    print_fl(fl);

    fl.pop_front();
    print_fl(fl);
}


int main() {
    test_list();
    test_forward_list();
    return 0;
}
