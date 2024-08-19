#include <iostream>
#include <vector>
using namespace std;


void print(vector<int>& v) {
    for (int i = 0;i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test_vector() {
    vector<int> v = {2, 3, 4, 8, 6 ,4, 1, -1};

    // Test push_back
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    print(v);

    // No such method
    // v.pop_front();

    cout << "Before fit, size: " << v.size() << ", capacity: " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "After fit, size: " << v.size() << ", capacity: " << v.capacity() << endl;

    // test iterator
    cout << "Test iterator: " << endl;
    vector<int>::iterator iter = v.begin();
    iter++;
    cout << *iter << endl;
    v.erase(iter);
    print(v);
}


int main() {
    test_vector();
    return 0;
}
