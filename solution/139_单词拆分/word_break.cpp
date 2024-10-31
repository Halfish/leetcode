#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct Compare {
    bool operator()(string &a, string &b) { return a.size() > b.size(); }
};

/*
 * 回溯法，会超时，因为有很多的重复计算。
 */
bool dfs(string s, vector<string> &wordDict) {
    if (s.size() == 0) {
        return true;
    }
    for (int i = 0; i < wordDict.size(); ++i) {
        if (wordDict[i].size() > s.size()) {
            continue;
        }
        if (wordDict[i] == s.substr(0, wordDict[i].size())) {
            bool flag = dfs(s.substr(wordDict[i].size()), wordDict);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<char> char_set;
    for (int i = 0; i < wordDict.size(); ++i) {
        for (int j = 0; j < wordDict[i].size(); ++j) {
            char_set.insert(wordDict[i][j]);
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (char_set.find(s[i]) == char_set.end()) {
            return false;
        }
    }
    sort(wordDict.begin(), wordDict.end(), Compare());
    for (int i = 0; i < wordDict.size(); ++i) {
        cout << wordDict[i] << " ";
    }
    cout << endl;
    return dfs(s, wordDict);
}

/*
 * 动态规划，正解
 */
bool wordBreak_2(string s, vector<string> &wordDict) {
    int n = s.size();
    bool dp[n];
    memset(dp, false, sizeof(dp));
    int index = -1;
    while (index < n) {
        if (index >= 0 && dp[index] == false) {
            index++;
            continue;
        }
        for (int i = 0; i < wordDict.size(); ++i) {
            if ((index + 1 + wordDict[i].size()) > s.size()) {
                continue;
            }
            if (s.substr(index + 1, wordDict[i].size()) == wordDict[i]) {
                dp[index + wordDict[i].size()] = true;
            }
        }
        index++;
    }
    return dp[n - 1];
}

int main() {
    vector<string> wordDict = {"apple", "pen"};
    string s = "applepenapple";

    wordDict = {"a", "b"};
    s = "ab";

    // wordDict = {"cats", "dog", "sand", "and", "cat"};
    // s = "catsandog";

    // wordDict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
    // "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    // s =
    // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    // "aaaaaaaaaab";

    cout << wordBreak_2(s, wordDict) << endl;
    return 0;
}