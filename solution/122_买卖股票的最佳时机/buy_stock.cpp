#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    int ans = 0;
    int min_p = -1;
    for (int i = 0; i < prices.size(); ++i) {
        if ((i == 0 || prices[i] <= prices[i - 1]) &&
            (i == (prices.size() - 1) || prices[i] <= prices[i + 1])) {
            min_p = prices[i];
        }
        if (min_p >= 0 && (i == 0 || prices[i] >= prices[i - 1]) &&
            ((i == prices.size() - 1) || prices[i] >= prices[i + 1])) {
            ans += (prices[i] - min_p);
            min_p = -1;
        }
    }
    return ans;
}

int maxProfit_2(vector<int> &prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i) {
        ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
}

int main() {
    vector<int> v = {7, 1, 1, 5, 3, 6, 4};
    cout << maxProfit(v) << endl;
    cout << maxProfit_2(v) << endl;
    return 0;
}