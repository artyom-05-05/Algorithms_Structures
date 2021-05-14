#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    vector<unordered_map<string, int>> levels;     // каждый блок - новый уровень
    int cur_level = 0;                             // текущий уровень
    unordered_map<string, int> dict_of_variables;  // словарь переменная - значение
    string cur_line;
    while (getline(cin, cur_line)) {               // перебираем построчно
        if (cur_line.find('{') != string::npos) {
            cur_level++;                           // перходим на след.уровень
            levels.push_back(dict_of_variables);   // запоминаем словарь переменных на сответств. уровень
            dict_of_variables.clear();             // очищаем словарь для нового уровня
        }
        else if (cur_line.find('}') != string::npos) {
            cur_level--;                           // перходим на пред.уровень
            dict_of_variables = levels.back();     // откатываем словарь до пред.уровня
            levels.pop_back();                     // стираем текущий уровень
        }
        else if (cur_line.find('=') != string::npos) {
            // Разбор строки
            int equal_sign_pos = cur_line.find('=');          // номер символа "="
            string name = cur_line.substr(0, equal_sign_pos); // выделяем имя переменной
            cur_line.erase(0, equal_sign_pos + 1);            // cur_line -- то, что справа от "="

            // Случай1: присваивание нового значения
            if (isdigit(cur_line[0]) || cur_line[0] == '-')
                dict_of_variables[name] = stoi(cur_line);

            // Случай2: копирование значения другой переменной
            else {
                if (dict_of_variables.count(cur_line) != 0)   // если такая переменная есть в словаре текущего уровня
                    dict_of_variables[name] = dict_of_variables[cur_line];
                else {                                        // иначе спускаемся вниз по уровням, пока не найдем
                    int l = cur_level - 1;                    // итератор по уровням
                    bool found_variable = false;
                    while (l >= 0) {
                        if (levels[l].count(cur_line) != 0) {
                            found_variable = true;
                            dict_of_variables[name] = (levels[l])[cur_line];
                            break;
                        }
                        else l--;
                    }
                    if (!found_variable) dict_of_variables[name] = 0;
                }
                cout << dict_of_variables[name] << endl;              // Вывод
            }
        }
    }
    return 0;
}