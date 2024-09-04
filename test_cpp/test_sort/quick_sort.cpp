#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &v, int i, int j) {
    if (i < 0 || j >= v.size() || i == j) {
        return;
    }
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/*
 * 快速排序，递归版本
 */
void quick_sort(vector<int> &v, int start, int end) {
    if (v.empty() || start < 0 || end >= v.size() || start >= end) {
        return;
    }

    int pivot = v[start]; // 选取第一个元素作为基准
    int i = start;        // i 始终放小于基准的元素

    // 找到一个小于基准的元素，将其放到 i 的位置
    for (int j = i; j <= end; ++j) {
        if (v[j] < pivot) {
            i++;
            swap(v, i, j);
        }
    }
    // 目前 i 位置的元素是最后一个小于基准的元素，将其与基准交换
    swap(v, start, i);
    quick_sort(v, start, i - 1);
    quick_sort(v, i + 1, end);
}

int main() {
    vector<int> v = {2, 3, 5, 3, 4, 2, 1, 8, 9, 7};
    quick_sort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
