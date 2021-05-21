#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

bool comp (string a, string  b) {
    a = a + b;
    b = b + a;
    return a > b;
}

int main() {
//Ввод массива строк
    vector<string> parts;
    string input_str;
    while (cin >> input_str) {
        parts.push_back(input_str);
    }
// Обработка
    sort(parts.begin(), parts.end(), comp);
// Вывод
    copy(parts.begin(), parts.end(), ostream_iterator<string>(cout, ""));
    return 0;
}