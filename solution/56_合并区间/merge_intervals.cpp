#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) { return v1[0] < v2[0]; }

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    if (intervals.size() == 0) {
        return ans;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
        if (end >= intervals[i][0]) {
            end = max(intervals[i][1], end);
        } else {
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    ans.push_back({start, end});
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
