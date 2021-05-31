#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
// Ввод
    int n, k;                               // n - кол-во товаров, k - параметр акции
    cin >> n >> k;
    vector<int> prices(n);                  // массив цен на товары, которые покупает Билл
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
// Обработка
    sort(prices.rbegin(), prices.rend());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i+1) % k == 0) continue;
        sum += prices[i];
    }
    for (int i = 0; i < n/k; i++)
        for (int j = 0; j < k-1; j++)
            sum += prices[i*k + j];

    for (int i = 0; i < n%k; i++)
        sum += prices[k * (n/k) + i];
// Вывод
    cout << sum;
    return 0;
}