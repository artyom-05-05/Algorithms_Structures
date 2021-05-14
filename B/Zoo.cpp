#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
//Ввод строки (маленькая буква - животное, большая - ловушка)
    string data;
    cin >> data;
//Обработка
    bool is_possible = false;       //Возможно ли вернуть всех животных в клетки
    struct object_with_num {
        char object;                //буква (ловушка или животное)
        int number;                 // № буквы (счёт ведется отдельно для заглавных и строчных букв)
    };
    int counter_upper_case = 0;     //счётчик заглавных букв (№ ловушки)
    int counter_lower_case = 0;     //счётчик строчных букв (№ животного)
    vector <int> cages(data.length() / 2); //массив с № животных на позиции № ловушки

    //Введем структуру СТЕКа
    stack <struct object_with_num> zoo;
    zoo.push({'0', 0});             //Добавим нулевой элемент для сравнения

    //Проходим по строке data: сравниваем текущую букву с верхней в стеке
    // если буквы не совпадают - запоминаем текщую в стек
    // если совпали - извлекаем из стека, запоминаем номер животного и номер клетки

    for (int i = 0; i < data.length(); i++) {
        //Определим текущий объект
        struct object_with_num cur_object{};
        if (isupper(data[i])) {
            counter_upper_case++;
            cur_object = {data[i], counter_upper_case};
        }
        else {
            counter_lower_case++;
            cur_object = {data[i], counter_lower_case};
        }

        //Случай: буквы не совпадают (добавляем текущий объект в стек)
        if (abs(cur_object.object - zoo.top().object) != 32) {
            zoo.push(cur_object);
        }
            //Случай: буквы совпали, одна - заглавная, другая - строчная (извлекаем из стека, запоминая номер животного)
        else {
            int cage, animal;
            if (isupper(cur_object.object)) {
                cage = cur_object.number;
                animal = zoo.top().number;
            }
            else {
                cage = zoo.top().number;
                animal = cur_object.number;
            }
            //Запоминаем № животного на позиции № ловушки
            cages[cage - 1] = animal;
            zoo.pop();
        }
    }
    //Если всех животных удалось вернуть в клетки
    if (zoo.top().object == '0') is_possible = true;

//Вывод
    if (is_possible) {
        cout << "Possible" << endl;
        for (int cage : cages) {
            cout << cage << " ";
        }
    }
    else {
        cout << "Impossible";
    }
    return 0;
}