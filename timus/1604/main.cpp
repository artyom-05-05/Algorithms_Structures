#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Sign {
    int index;
    int quantity;
};
struct comparator {
    bool operator()(Sign& a, Sign& b) {
        return (a.quantity < b.quantity);
    }
};

int main() {
/// Ввод
    int k, cur_quantity;                             /// k - кол-во различных видов знаков
    cin >> k;

    priority_queue<Sign, vector<Sign>, comparator> signs;
    for (int i = 0; i < k; i++) {
        cin >> cur_quantity;                         /// cur_quantity - временная переменная для ввода
        signs.push({.index = i + 1, .quantity = cur_quantity});
    }

/// Обработка
    Sign max_sign, max2_sign;
    while (!empty(signs)) {

        max_sign = signs.top();
        signs.pop();
        max_sign.quantity--;
        cout << max_sign.index << " ";

        bool flag = false;
        if (!empty(signs)) {
            flag = true;
            max2_sign = signs.top();
            signs.pop();
            max2_sign.quantity--;
            cout << max2_sign.index << " ";
        }
        if (max_sign.quantity > 0) signs.push(max_sign);
        if (max2_sign.quantity > 0 && flag) signs.push(max2_sign);
    }
    return 0;
}