#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> dict_of_variables;  // акутальный словарь (переменная - значение)
    stack<unordered_map<string, int>> levels;     // каждый блок - новый уровень (храним значения до изменения)
    unordered_map<string, int> level_changes;
    string cur_line;

    while (getline(cin, cur_line)) {
        if (cur_line[0] == '{') {
            levels.push(level_changes);
            level_changes.clear();                  // очищаем словарь изменений
        }
        else if (cur_line[0] == '}') {
            for (auto var: level_changes) {
                dict_of_variables[var.first] = level_changes[var.first];
            }
            level_changes = levels.top();
            levels.pop();                           // стираем текущий уровень
        }
        else if (cur_line.find('=') != string::npos) {
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
