#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // for (int i = 0; i < nums.size(); ++ i) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        // 分成三组 正数、负数、零
        // case 1: 0, 0, 0  // O(1)
        // case 2: 0, +, -  // O(N)
        // case 3: +, +, -  // O(N * N)
        // case 4: +, -, -
        vector<vector<int>> ans;
        unordered_set<int> s_pos;
        unordered_set<int> s_neg;

        vector<int> neg;
        vector<int> pos;
        vector<int> zeros;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zeros.push_back(i);
            } else if (nums[i] > 0) {
                pos.push_back(i);
            } else {
                neg.push_back(i);
            }
        }

        // cout << zeros.size() << " " << pos.size() << " " << neg.size() <<
        // endl;

        // case 1
        if (zeros.size() >= 3) {
            ans.push_back({0, 0, 0});
        }

        // case 2
        if (zeros.size() > 0) {
            for (int i = 0; i < pos.size(); ++i) {
                // cout << "i = " << i << ", pos[i] = " << pos[i] << ",
                // nums[pos[i]] = " << nums[pos[i]] << endl;
                if (s_pos.find(nums[pos[i]]) != s_pos.end()) {
                    continue;
                }
                s_pos.insert(nums[pos[i]]);
                for (int j = 0; j < neg.size(); ++j) {
                    // cout << "j = " << j << ", neg[j] = " << neg[j] << ",
                    // nums[neg[j]] = " << nums[neg[j]] << endl;
                    if (nums[pos[i]] + nums[neg[j]] == 0) {
                        ans.push_back({0, nums[pos[i]], nums[neg[j]]});
                        break;
                    }
                }
            }
            s_pos.clear();
        }

        // case 3
        for (int i = 0; i < pos.size(); ++i) {
            if (s_pos.find(nums[pos[i]]) != s_pos.end()) {
                continue;
            }
            s_pos.insert(nums[pos[i]]);
            s_neg.clear();
            for (int j = 0; j < neg.size(); ++j) {
                if (s_neg.find(nums[neg[j]]) != s_neg.end()) {
                    continue;
                }
                s_neg.insert(nums[neg[j]]);
                for (int k = j + 1; k < neg.size(); ++k) {
                    if (nums[pos[i]] + nums[neg[j]] + nums[neg[k]] == 0) {
                        ans.push_back(
                            {nums[pos[i]], nums[neg[j]], nums[neg[k]]});
                        break;
                    }
                }
            }
        }
        s_pos.clear();
        s_neg.clear();

        // case 4:
        for (int i = 0; i < neg.size(); ++i) {
            if (s_neg.find(nums[neg[i]]) != s_neg.end()) {
                continue;
            }
            s_neg.insert(nums[neg[i]]);
            s_pos.clear();
            for (int j = 0; j < pos.size(); ++j) {
                if (s_pos.find(nums[pos[j]]) != s_pos.end()) {
                    continue;
                }
                s_pos.insert(nums[pos[j]]);
                for (int k = j + 1; k < pos.size(); ++k) {
                    if (nums[neg[i]] + nums[pos[j]] + nums[pos[k]] == 0) {
                        ans.push_back(
                            {nums[neg[i]], nums[pos[j]], nums[pos[k]]});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> ans = s.threeSum(v);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}