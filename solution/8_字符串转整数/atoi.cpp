#include <iostream>
#include <string>
using namespace std;

const int max_num = 2147483647;

class Solution {
  public:
    int myAtoi(string s) {
        bool isNegative = false;
        long number = 0;

        int start = 0;
        while (start < s.size()) {
            if (s[start] == ' ') {
                start++;
                continue;
            } else if (s[start] == '+') {
                start++;
                isNegative = false;
            } else if (s[start] == '-') {
                start++;
                isNegative = true;
            }
            break;
        }
        if (start >= s.size() || s[start] < '0' || s[start] > '9') {
            return 0;
        }
        for (int i = start; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') {
                break;
            }
            number = number * 10 + (s[i] - '0');
            if (i < s.size() - 1 && s[i + 1] >= '0' && s[i + 1] <= '9') {
                if (number > 214748364) {
                    return isNegative ? -max_num - 1 : max_num;
                }
                if (number == 214748364 && s[i + 1] >= '0') {
                    if (isNegative && s[i + 1] > '8' ||
                        !isNegative && s[i + 1] > '7') {
                        return isNegative ? -max_num - 1 : max_num;
                    }
                }
            }
        }
        return isNegative ? -number : number;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("00123") << endl;
    cout << s.myAtoi("-123") << endl;
    cout << s.myAtoi("-2147483648") << endl;
    cout << s.myAtoi("2147483648") << endl;
    cout << s.myAtoi("21474836460") << endl;
    cout << s.myAtoi("+2147483647") << endl;
    cout << s.myAtoi("0-1") << endl;
    cout << s.myAtoi("word and 098") << endl;
    cout << s.myAtoi("000000012344555") << endl;
    return 0;
}