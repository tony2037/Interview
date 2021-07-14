#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int> &v, int i, int j) {
    int tmp = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = tmp;
}

void partition(vector<int> &v, int l, int r) {
    int p = v.at(l);
    int less = l;
    int j = l;
    int great = r;
    while (j <= great) {
        if (v.at(j) < p) {
            swap(v, j, less);
            less++;
            j++;
        }
        else if (v.at(j) > p) {
            swap(v, j, great);
            great--;
        }
        else {
            j++;
        }
    }
}

int main() {
    vector<int> v = {1,0,1,2,0,1,2};
    partition(v, 0, v.size() - 1);
    for (int i : v) {
        cout << i << " ";
    }    
    cout << "\n";
}