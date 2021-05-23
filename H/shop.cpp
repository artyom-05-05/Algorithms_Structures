#include <iostream>
#include <algorithm>
using namespace std;

bool comp (int a, int b) {
    return a < b;
}

int main() {
// Ввод
    int n, k;                       // n - кол-во товаров, k - параметр акции
    cin >> n >> k;
    int prices[n];                  // массив цен на товары, которые покупает Билл
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
// Обработка
    sort(prices, prices + n, comp);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i+1) % k == 0) continue;
        sum += prices[i];
    }
// Вывод
    cout << sum;
    return 0;
}