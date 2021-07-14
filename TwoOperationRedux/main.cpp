#include <iostream>
using namespace std;
int findMaxNum(int x, int y, int z, int max_x) {
    int ans = -1;
    max_x = max(max_x, x);
    if(z == 0) {
        if (x == y)
            return max_x;
        else return ans;
    }
    int ret_up = -1;
    int ret_down = -1;
    ret_up = findMaxNum(x + 1, y, z - 1, max_x);
    if (-1 != ret_up)
        max_x = max(max_x, ret_up);
    ret_down = findMaxNum(x - 1, y, z - 1, max_x);
    if (-1 != ret_down)
        max_x = max(max_x, ret_down);
    if (-1 == ret_up && -1 == ret_down) {
        return -1;
    }
    return max_x;
}

int main() {
    int ret = findMaxNum(6, 4, 4, 0);
    cout << ret << "\n";
}