#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, total_sum = 0;                         /// total_sum - сумма весов всех камней
int weights[20];                              /// массив весов

int sum_calculation(int comb) {               /// Вспомогательная ф-ия для суммирования камней, входящих в кучку
    int cur_sum = 0;                          /// cur_sum - вес одной кучки
    for (int i = 0; i < n - 1; i++) {
        if (comb & (1 << i))                  /// битовая маска: проверка на наличие i-го бита в 2-ной записи
            cur_sum += weights[i];
    }
    return cur_sum;
}
int main() {
/// Ввод
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        total_sum += weights[i];
    }
/// Обработка
    int cur_sum, dif, min_dif = 100000;               /// dif - текущая разница между кучками, min_dif - минимальная разница
    for (int comb = 1; comb < (1 << n); comb++) {     /// (1 << n) = 2^n - кол-во всевозможных комбинаций
        cur_sum = sum_calculation(comb);
        dif = abs(total_sum - 2 * cur_sum);
        min_dif = min(dif, min_dif);
    }
/// Вывод
    cout << min_dif;
    return 0;
}