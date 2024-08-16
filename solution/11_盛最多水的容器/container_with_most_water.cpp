#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int maxArea(vector<int> &height) {
    int i = 0;
    int j = height.size() - 1;
    int area = 0;
    while (i < j) {
        int currArea = (j - i) * min(height[j], height[i]);
        if (currArea > area) {
            area = currArea;
        }
        if (height[i] < height[j]) {
            while (i < j) {
                i++;
                if (height[i] > height[i - 1]) {
                    break;
                }
            }
        } else {
            while (i < j) {
                j--;
                if (height[j] > height[j + 1]) {
                    break;
                }
            }
        }
    }
    return area;
}

int main() {
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    //vector<int> v = {2, 3, 10, 5, 7, 8, 9};
    cout << maxArea(v) << endl;
    return 0;
}
