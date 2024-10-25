#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int rand_7() { return rand() % 7 + 1; }

int rand_10() {
    bool is_first = true;
    while (true) {
        int num = rand_7();
        if (num == 7) {
            continue;
        }
        is_first = num <= 3;
        break;
    }
    int reminder = 0;
    while (true) {
        reminder = rand_7();
        if (reminder > 5) {
            continue;
        }
        break;
    }
    return reminder + (is_first ? 0 : 5);
}

int main() {
    for (int i = 0; i < 100; ++i) {
        cout << rand_10() << " ";
    }
    return 0;
}