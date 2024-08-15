#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, pair<string, int>> reminder_100_map = {
    {1, make_pair("C", 100)},  {2, make_pair("C", 100)},
    {3, make_pair("C", 100)},  {4, make_pair("CD", 400)},
    {5, make_pair("D", 500)},  {6, make_pair("D", 500)},
    {7, make_pair("D", 500)},  {8, make_pair("D", 500)},
    {9, make_pair("CM", 900)},
};

unordered_map<int, pair<string, int>> reminder_10_map = {
    {1, make_pair("X", 10)},  {2, make_pair("X", 10)}, {3, make_pair("X", 10)},
    {4, make_pair("XL", 40)}, {5, make_pair("L", 50)}, {6, make_pair("L", 50)},
    {7, make_pair("L", 50)},  {8, make_pair("L", 50)}, {9, make_pair("XC", 90)},
};

unordered_map<int, pair<string, int>> reminder_1_map = {
    {1, make_pair("I", 1)},  {2, make_pair("I", 1)}, {3, make_pair("I", 1)},
    {4, make_pair("IV", 4)}, {5, make_pair("V", 5)}, {6, make_pair("V", 5)},
    {7, make_pair("V", 5)},  {8, make_pair("V", 5)}, {9, make_pair("IX", 9)},
};

string intToRoman(int num) {
    string ans;
    while (num) {
        int reminder_100 = num / 100;
        int reminder_10 = num / 10;
        int reminder_1 = num % 10;
        if (num / 1000 > 0) {
            ans += "M";
            num -= 1000;
        } else if (reminder_100 >= 1) {
            ans += reminder_100_map[reminder_100].first;
            num -= reminder_100_map[reminder_100].second;
        } else if (reminder_10 >= 1) {
            ans += reminder_10_map[reminder_10].first;
            num -= reminder_10_map[reminder_10].second;
        } else if (reminder_1 >= 1) {
            ans += reminder_1_map[reminder_1].first;
            num -= reminder_1_map[reminder_1].second;
        }
    }
    return ans;
}

int main() {
    cout << intToRoman(3) << endl;
    cout << intToRoman(58) << endl;
    cout << intToRoman(3749) << endl;
    cout << intToRoman(1994) << endl;
    return 0;
}
