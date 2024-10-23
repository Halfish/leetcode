#include <iostream>
using namespace std;


int mySqrt(int x) {
    long left = 0;
    long right = max(1, x / 2);
    while(left <= right) {
        long mid = (left + right) / 2;
        long s = mid * mid;
        if (s == x) {
            return mid;
        } else if (s > x) {
            right = mid - 1;
        } else if (s < x) {
            left = mid + 1;
            if (left * left > x) {
                return left - 1;
            }
        }
    }
    return left;
}


int mySqrt2(int x) {
    int ans = 0;
    int left = 0;
    int right = x;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long s = mid * mid;
        if (s <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}


int main() {
    cout << mySqrt(36) << endl;
    cout << mySqrt(88) << endl;

    cout << mySqrt2(3) << endl;
    cout << mySqrt2(8) << endl;
    cout << mySqrt2(81) << endl;
    cout << mySqrt2(82) << endl;
    return 0;
}