#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() {
  // Test set
  unordered_set<int> s;
  s.insert(1);
  s.insert(10);
  s.insert(8);
  for (unordered_set<int>::iterator iter = s.begin(); iter != s.end(); ++ iter) {
    cout << *iter << endl;
  }
  for (const int & ele : s) {
    cout << ele << endl;
  }

  // Test map
  unordered_map<string, int> m;
  m.insert(make_pair("Bruce", 3));
  for (auto iter = m.begin(); iter != m.end(); ++ iter) {
    cout << iter->first << ", " << iter->second << endl;
  }
  if (m.find("Bruce") != m.end()) {
    int age = m["Bruce"];
    cout << age << endl;
  }
  return 0;
}

/*
 * compile with `g++ test_hash.cpp -std=c++11`.
 */
