#include <iostream>
#include <string>
#include <vector>
using namespace std;

string addStrings(string num1, string num2) {
    vector<char> ans;
    int reminder = 0;
    int sum = 0;
    vector<char> v;
    int index = max(num1.size(), num2.size());
    for (int i = 0; i < index; ++i) {
        sum = reminder;
        if (i < num1.size()) {
            sum += num1[num1.size() - i - 1] - '0';
        }
        if (i < num2.size()) {
            sum += num2[num2.size() - i - 1] - '0';
        }
        reminder = sum / 10;
        sum = sum % 10;
        ans.push_back(sum + '0');
    }
    if (reminder > 0) {
        ans.push_back(reminder + '0');
    }
    string ans_s;
    for (int i = ans.size() - 1; i >= 0; i--) {
        ans_s.push_back(ans[i]);
    }
    return ans_s;
}

int main() {
    cout << addStrings("1345", "293") << endl;
    cout << addStrings("13", "2348") << endl;
    return 0;
}