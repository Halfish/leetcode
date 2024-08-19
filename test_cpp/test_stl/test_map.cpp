#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void test_map() {
    // Test map
    map<string, int> m;
    m.insert(make_pair("page", 1));
    m.insert(make_pair("name", 9));
    m.insert(make_pair("index", 3));

    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " --> " << iter->second << endl;
    }
    cout << endl;

    if (m.find("page") != m.end()) {
        cout << "page -> " << m["page"] << endl;
    }
    cout << m["no_such_key"] << endl;
}


void test_set() {
    set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(2);
    for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << ", ";
    }
    cout << endl;

    if (s.find(3) == s.end()) {
        cout << "3 not found!" << endl;
    } else {
        cout << "Found 3!" << endl;
    }
}


void test_unordered_map() {
    unordered_map<string, int> m;
    m["name"] = 13;
    m["age"] = 4;
    m.insert(make_pair("index", 3));
    for (unordered_map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " --> " << iter->second << endl;
    }
    if (m.find("name") != m.end()) {
        cout << "found! name -> " << m["name"] << endl;
    } else {
        cout << "name not found!" << endl;
    }
}


void test_unordered_set() {
    unordered_set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(2);
    for (unordered_set<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << ", ";
    }
    cout << endl;

    if (s.find(3) == s.end()) {
        cout << "3 not found!" << endl;
    } else {
        cout << "Found 3!" << endl;
    }
}


int main() {
    cout << "Test map" << endl;
    test_map();

    cout << "\nTest set" << endl;
    test_set();

    cout << "\nTest unordered_map" << endl;
    test_unordered_map();

    cout << "\nTest unordered_set" << endl;
    test_unordered_set();
    return 0;
}
