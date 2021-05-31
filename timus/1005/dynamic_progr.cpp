#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dyn_progr() {
    int n, sum = 0;
// Ввод
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
// Обработка
    vector<vector<int>> p(n+1, vector<int>(sum+1));

    for (int j = 0; j <= sum; j++) {
        p[0][j] = 0;
    }
    for (int i = 0; i <= n; i++) {
        p[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= a[i-1])
                p[i][j] = max(p[i - 1][j], p[i - 1][j - a[i-1]]);
            else p[i][j] = p[i - 1][j];
        }
    }
    int min_sum = sum;
    for (int i = 1; i <= sum/2; i++) {
        if (p[n][i] == 1 && (sum - 2*i) < min_sum) {
            min_sum = sum - 2*i;
        }
    }
// Вывод
    cout << min_sum;
    return 0;
}

