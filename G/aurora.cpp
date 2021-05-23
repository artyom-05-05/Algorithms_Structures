#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int32_t> weights;

bool comp (char a, char b) {
    return weights[a] > weights[b];
}

int main() {
    string input_str;
    string weighted_str;                //Часть строки, кот. нужно разнести по бокам (повторяются более 2 раз)
    string others;                      //Часть строки, с остальными буквами (встречаются по 1 разу)
    int letter_quantity;                //Кол-во появлений буквы в строке

    cin >> input_str;                   // Ввод строки

    for (int i = 0; i < 26; i++) {
        cin >> weights['a' + i];        // Заполнение словаря весов
        letter_quantity = count(input_str.begin(), input_str.end(), 'a' + i);
        if (letter_quantity >= 2) {
            weighted_str += 'a' + i;
            if (letter_quantity > 2)
                others.append(letter_quantity - 2, 'a' + i);
        }
        else if (letter_quantity == 0) continue;
        else others += 'a' + i;
    }

    sort(weighted_str.begin(), weighted_str.end(), comp);

    cout << weighted_str << others;
    reverse(weighted_str.begin(), weighted_str.end());
    cout << weighted_str;

    return 0;
}
