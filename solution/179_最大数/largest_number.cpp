#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Compare {
    public:
    bool operator()(string a, string b) {
        return (a + b) > (b + a);
    }
};

string largestNumber(vector<int> &nums) {
    vector<string> strs;
    for (int i = 0; i < nums.size(); ++i) {
        strs.push_back(to_string(nums[i]));
    }
    sort(strs.begin(), strs.end(), Compare());
    string ans;
    for (int i = 0; i < strs.size(); ++i) {
        ans += strs[i];
    }
    if (ans[0] == '0') {
        return "0";
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    //nums = {8308, 8308, 830};
    //nums = {111311,1113};
    cout << largestNumber(nums) << endl;
    return 0;
}