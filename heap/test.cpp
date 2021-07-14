#include <vector>
#include <iostream>
#include "heapsort.h"

int main() {
    vector<int> test1 = {8, 5, 2, 9, 5, 6, 3};
    vector<int> expect1 = {2, 3, 5, 5, 6, 8, 9};
    vector<int> ans = heapSort(test1);
    for (int num : expect1) {
        cout << num << " ";
    }
    cout << "\n";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << "\n";
}
