#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, cur_number;
    int cur_sum = 0, max_sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cur_number;
        cur_sum = max(cur_sum + cur_number, 0);
        max_sum = max(cur_sum, max_sum);
    }
    cout << max_sum;
    return 0;
}
