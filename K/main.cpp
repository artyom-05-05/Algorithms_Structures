#include <iostream>
#include <vector>
using namespace std;

struct Block {
    int start;                      /// номер 1-го элемента
    int length;                     /// кол-во ячеек
    int request_num;                /// номер запроса
    bool is_free;                   /// блок свободен / занят
};

vector<Block> memory;

int allocate_block(int K, int cur_request_num) {
    int min_dif = INT32_MAX, dif, i_best;
    for (int i = 0; i < memory.size(); i++) {                   /// Поиск наиболее подходящего свободного блока
        dif = memory[i].length - K;
        if (memory[i].is_free && dif >= 0 && dif < min_dif) {
            min_dif = dif;
            i_best = i;
        }
    }
    if (min_dif != INT32_MAX) {                                 /// Свободный блок найден
        memory[i_best] = {.start = memory[i_best].start,        /// Заполнение найденного блока
                         .length = K,
                         .request_num = cur_request_num,
                         .is_free = false};
        if (min_dif != 0) {                                     /// Если блок заполнили не полностью ->
            Block extra_block = {.start = memory[i_best].start + K,   /// вставить дополнительный пустой блок
                                 .length = min_dif,
                                 .request_num = 0,
                                 .is_free = true};
            if (i_best == memory.size() - 1) memory.push_back(extra_block);
            else memory.insert(memory.cbegin() + i_best + 1, extra_block);
        }
        return memory[i_best].start;
    }
    else return -1;                                             /// Свободный блок НЕ найден -> отклонить запрос
}

void free_block(int T) {                // найти по номеру, освободить (проверить близлежащие, если свободны - объединить
    for (int i = 0; i < memory.size(); i++) {
        if (memory[i].request_num == T) {                          /// Поиск блока по номеру запроса
            memory[i].is_free = true;                              /// Освобождение
            if (i != memory.size() - 1 && memory[i+1].is_free) {   /// Проверка соседних блоков
                memory[i].length += memory[i+1].length;            /// если тоже свободны -> Объединить в один
                memory.erase(memory.cbegin() + (i + 1));
            }
            if (i != 0 && memory[i-1].is_free) {
                memory[i-1].length += memory[i].length;
                memory.erase(memory.cbegin() + i);
            }
            break;
        }
    }
}

int main() {
    int N, M, request;                      /// N - кол-во ячеек памяти, M - кол-во запросов, request - запрос
    cin >> N >> M;
    memory.push_back({1, N, 0, true});      /// Большой пустой блок

    for (int i = 1; i <= M; i++) {                              /// Обработка поступающих запросов
        cin >> request;
        if (request > 0)                                        /// 2 действия:
            cout << allocate_block(request, i) << endl;         /// выделить блок
        else free_block(request * (-1));                        /// освободить блок
    }
    return 0;
}