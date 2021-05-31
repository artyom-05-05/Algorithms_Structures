#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseBWT(int k, string s) {
    const int N = s.length();   //// количество символов во входной строке
    const int M = (122-65) + 1; //// количество символов в алфавите (от 'A' до 'a')

    int count[M] = {0};         //// массив частот символов
    for (auto c: s)
        count[c - 'A']++;

    int sum = 0;                        //// Упорядочиваем символы, чтобы получить первый столбец исходной матрицы
    for (int i = 0; i < M; i++) {       //// count[i] указывает на первую позицию символа i в первом столбце
        sum = sum + count[i];
        count[i] = sum - count[i];
    }

    vector<int> t(N, 0);                //// Cоздаем вектор обратного преобразования
    for (int i = 0; i < N; i++) {
        t[count[s[i] - 'A']] = i;
        count[s[i] - 'A']++;
    }

    int j = t[k - 1];                  //// Восстанавливаем исходный текст
    string answer(N, ' ');
    for (int i = 0; i < N; i++) {
        answer[i] = s[j];
        j = t[j];
    }
    return answer;
}
int main() {
    int k;            //// номер исходной строки в матрице сдвигов
    string s;         //// входящая строка
// Ввод
    cin >> k >> s;
// Обработка
    string s_original = reverseBWT(k, s);
    cout << s_original;
    return 0;
}