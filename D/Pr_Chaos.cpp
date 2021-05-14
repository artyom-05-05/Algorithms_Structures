#include <iostream>
using namespace std;

int main() {
//Ввод переменных
    // a - изначальное число бактерий
    // b - число новых из 1 бактерии за день (в инкубаторе)
    // c - забираем для опытов
    // d - помещаем в конце дня обратно в контейнер
    // k - кол-во дней эксперимента
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
//Обработка
    int cur_number = a;                 //текущее число бактерий в контейнере
    int prev_number = 0;                //число бактерий день назад
    for (int i = 0; i < k; i++) {
        if (cur_number * b < c) {       //ПРОВЕРКА: если после размножения осталось меньше с бактерий
            cur_number = 0;
            break;
        }
        if (cur_number == prev_number)  //прерывание цикла, в случае совпадения эксперимента
            break;
        prev_number = cur_number;       //сохраняем предыдущее значение
        if (cur_number * b - c < d)     //если в конце дня осталось больше d бактерий, излишек отбрасываем
            cur_number = cur_number * b - c;
        else cur_number = d;
    }
//Вывод
    cout << cur_number;
    return 0;
}