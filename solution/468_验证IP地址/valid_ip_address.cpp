#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string query, char seperator) {
    vector<string> ans;
    string cur;
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == seperator) {
            ans.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(query[i]);
        }
    }
    ans.push_back(cur);
    return ans;
}

bool validV4(string num) {
    if (num.size() > 1 && num[0] == '0') {
        return false;
    }
    if (num.empty() || num.size() > 3) {
        return false;
    }
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] < '0' || num[i] > '9') {
            return false;
        }
    }
    int n = stoi(num);
    if (n >= 256 || n < 0) {
        return false;
    }
    return true;
}

bool validV6(string num) {
    if (num.size() == 0 || num.size() > 4) {
        return false;
    }
    for (int i = 0; i < num.size(); ++i) {
        if (!(num[i] >= 'a' && num[i] <= 'f' ||
              num[i] >= 'A' && num[i] <= 'F' ||
              num[i] >= '0' && num[i] <= '9')) {
            return false;
        }
    }
    return true;
}

bool validIPv4(string queryIP) {
    vector<string> v = split(queryIP, '.');
    if (v.size() != 4) {
        return false;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (!validV4(v[i])) {
            return false;
        }
    }
    return true;
}

bool validIPv6(string queryIP) {
     vector<string> v = split(queryIP, ':');
    if (v.size() != 8) {
        return false;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (!validV6(v[i])) {
            return false;
        }
    }
    return true;
}

string validIPAddress(string queryIP) {
    if (validIPv4(queryIP)) {
        return "IPv4";
    }
    if (validIPv6(queryIP)) {
        return "IPv6";
    }
    return "Neither";
}

int main() {
    cout << validIPAddress("1e2.16.254.1") << endl;
    cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << endl;
    return 0;
}