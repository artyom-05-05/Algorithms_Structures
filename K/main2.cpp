#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Block {
    int start;                      /// номер 1-го элемента
    int length;                     /// кол-во ячеек
    bool is_free;                   /// блок свободен / занят
    struct Block *prev;
    struct Block *next;
};

auto comparator = [](struct Block* a, struct Block* b) {          /// Сравнение элементов в сете
    if (a->length == b->length) {
        return a->start > b->start;
    }
    return a->length > b->length;
};
set<struct Block*, decltype(comparator)> free_blocks(comparator); /// Сет размеров свободных блоков (по убыванию)
vector<struct Block*> requests;

int allocate_block(int K) {                                       /// Функция выделения блока
    auto iter = free_blocks.begin();
    if (!free_blocks.empty() && (*iter)->length >= K) {           /// Найден подходящий свободный блок
        if ((*iter)->length == K) {                               /// Случай: блок подходит идеально
            (*iter)->is_free = false;
            requests.push_back(*iter);
            free_blocks.erase(*iter);
        }
        else {                                  /// Остается место (создаем новый свободный блок + обновляем найденный)
            Block* extra_block = new Block{(*iter)->start + K, (*iter)->length - K, true, (*iter), (*iter)->next};
            if ((*iter)->next) (*iter)->next->prev = extra_block;

            Block* old_block = *iter;
            free_blocks.erase(*iter);
            *old_block = {old_block->start, K, false, old_block->prev, extra_block};
            free_blocks.insert(extra_block);
            requests.push_back(old_block);
        }
        return requests.back()->start;                            /// Выделение блока прошло успешно
    }
    else {
        requests.push_back(nullptr);
        return -1;                                                /// Не удалось найти подходящий свободный блок
    }
}
void merge_nodes(struct Block *a, struct Block *b) {         /// Вспомогательная процедура слияния узлов списка
    a->next = b->next;
    if (b->next) b->next->prev = a;
    a->length += b->length;
    delete(b);
}

void free_block(int T) {
    requests.push_back(nullptr);
    if (requests[T]) {
        Block* block = requests[T];
        requests[T] = nullptr;
        block->is_free = true;                                   /// Освобождение блока по номеру запроса

        if (block->prev && block->prev->is_free) {   /// Проверка предыдущего блока (слияние)
            free_blocks.erase(block->prev);
            block = block->prev;
            merge_nodes(block, block->next);
        }
        if (block->next && block->next->is_free) {   /// Проверка следующего блока (слияние)
            free_blocks.erase(block->next);
            merge_nodes(block, block->next);
        }
        free_blocks.insert(block);
    }
}

int main() {
    int N, M, cur_request;              /// N - кол-во ячеек памяти, M - кол-во запросов, cur_request - текущий запрос
    cin >> N >> M;
    free_blocks.insert(new Block{1, N, true, nullptr, nullptr}); /// Большой пустой блок
    requests.reserve(M);

    for (int i = 0; i < M; i++) {                                /// Обработка поступающих запросов
        cin >> cur_request;
        if (cur_request > 0)                                     /// 2 действия:
            cout << allocate_block(cur_request) << endl;         /// выделить блок
        else free_block(-1 * cur_request - 1);                   /// освободить блок
    }
    return 0;
}