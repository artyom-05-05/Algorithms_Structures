#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int N, K, P;                  /// N - общее число машинок, K - максимум машинок на полу, P - кол-во строк
    cin >> N >> K >> P;
/// Ввод послед-ти машинок + Обработка позиций
    vector<int> cars_order(P);          /// Послед-ть машинок в том порядке, в котором Петя захочет с ними играть
    vector<set<int>> positions(N);      /// Для каждой машинки запомним позиции в послед-ти (positions[№ машинки] = {позиции})
    for (int i = 0; i < P; i++) {
        cin >> cars_order[i];
        --cars_order[i];                /// чтобы № машинок начинались с [0]
        positions[cars_order[i]].insert(i);
    }
/// Обработка запросов (1. След машинка уже на полу: continue
///                     2. На полу есть место (кэш не переполнен): просто берем нужную с полки
///                     3. На полу нет места: 1 машинку убрать на полку (которая не понадобится дольше всего)
///                        и взять нужную
    map<int, int> floor;               /// массив машинок на полу (max: K)  floor[№ позиции след.встречи] = № машинки
    int counter = 0;                   /// мин кол-во операций, которое надо совершить
    for (int i = 0; i < P; i++) {
        auto cur_pos = positions[cars_order[i]].begin();            /// удаляем текущую позицию
        positions[cars_order[i]].erase(cur_pos);

        /// Запрос 1 типа
        if (floor.count(i)) {
            if (!positions[cars_order[i]].empty()) {
                floor.erase(i);
                floor[*positions[cars_order[i]].begin()] = cars_order[i];
            }
            else floor.erase(i);
            continue;
        }
        /// Очистить место, если весь пол занят
        if (floor.size() == K)
            floor.erase(--floor.end());

        if (!positions[cars_order[i]].empty())
            floor[*positions[cars_order[i]].begin()] = cars_order[i];     /// обновляем след позицию текущей машинки
        else floor[P+i] = cars_order[i];          /// больше не понадобятся (переносим ближе к удалению)

        counter++;
    }
    cout << counter;
    return 0;
}