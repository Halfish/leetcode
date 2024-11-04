#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, vector<int>> m;

    for (int i = 0; i < prerequisites.size(); ++i) {
        if (m.find(prerequisites[i][0]) != m.end()) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        } else {
            m[prerequisites[i][0]] = vector<int>({prerequisites[i][1]});
        }
    }

    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        vector<bool> visited(numCourses, false);
        queue<int> q;
        q.push(iter->first);
        // bfs 判断当前节点是否是环的开头
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            visited[top] = true;
            if (m.find(top) == m.end()) {
                continue;
            }
            for (int i = 0; i < m[top].size(); ++i) {
                if (m[top][i] == iter->first) {
                    return false;
                }
                if (!visited[m[top][i]]) {
                    q.push(m[top][i]);
                }
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> pre = {{1, 0}, {2, 0}, {2, 1}};
    cout << canFinish(3, pre) << endl;
    return 0;
}