#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> dict_of_variables;  // акутальный словарь (переменная - значение)
    vector<unordered_map<string, int>> levels;     // каждый блок - новый уровень (храним значения до изменения)
    unordered_map<string, int> level_changes;
    string cur_line;

    while (getline(cin, cur_line)) {
        switch(cur_line[0]) {
            case '{':
                levels.push_back(level_changes);
                level_changes.clear();                  // очищаем словарь изменений
                break;
            case '}':
                for (auto var: level_changes)
                    dict_of_variables[var.first] = var.second;
                level_changes = levels.back();
                levels.pop_back();                           // стираем текущий уровень
                break;
            default:
                // Разбор строки
                int equal_sign_pos = cur_line.find('=');          // номер символа "="
                string name = cur_line.substr(0, equal_sign_pos); // выделяем имя переменной
                cur_line.erase(0, equal_sign_pos + 1);            // cur_line -- то, что справа от "="

                // Случай1: присваивание нового значения
                if (isdigit(cur_line[0]) || cur_line[0] == '-') {
                    if (level_changes.count(name) == 0)
                        level_changes[name] = dict_of_variables[name]; // запоминаем пред.значение переменной
                    dict_of_variables[name] = stoi(cur_line);
                }
                // Случай2: копирование значения другой переменной
                else {
                    if (level_changes.count(name) == 0)
                        level_changes[name] = dict_of_variables[name]; // запоминаем пред.значение переменной
                    dict_of_variables[name] = dict_of_variables[cur_line];

                    cout << dict_of_variables[name] << endl;              // Вывод
                }
        }
    }
    return 0;
}
