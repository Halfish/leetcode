#include <climits>
#include <iostream>
#include <queue>
using namespace std;

string removeKdigits(string num, int k) {
    deque<char> q;
    int count = 0;
    int i;
    for (i = 0; i < num.size(); ++i) {
        if (count < k) {
            while (!q.empty() && num[i] < q.back()) {
                if (count == k) {
                    break;
                }
                q.pop_back();
                count++;
            }
        }
        q.push_back(num[i]);
    }
    while (count < k) {
        q.pop_back();
        count++;
    }
    while (!q.empty() && q.front() == '0') {
        q.pop_front();
    }
    if (q.empty()) {
        q.push_back('0');
    }
    string s(q.begin(), q.end());
    return s;
}

int main() {
    cout << removeKdigits("1432219", 3) << endl;
    return 0;
}
