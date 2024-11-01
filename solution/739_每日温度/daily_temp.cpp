#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> ans(temperatures.size());
    stack<int> s;
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        ans[s.top()] = 0;
        s.pop();
    }
    return ans;
}

int main() {
    vector<int> tmp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(tmp);
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}