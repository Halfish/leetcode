#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
        return 0;
    }
    int min = prices[0];
    int max = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < min) {
            min = prices[i];
        }
        if (prices[i] - min > max) {
            max = prices[i] - min;
        }
    }
    return max;
}

int main() {
    vector<int> v = {7, 1, 5, 3, 6, 4};
    vector<int> v2 = {7, 6, 4, 3, 1};
    cout << maxProfit(v) << endl;
    cout << maxProfit(v2) << endl;

    return 0;
}