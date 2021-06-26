#include <iostream>
#include <vector>
using namespace std;

vector<int> moneyboxes;                /// массив копилок
vector<int> color;                     /// массив уже открытых копилок
int min_broken = 0;                    /// мин. кол-во копилок, которые надо разбить (кол-во циклов в графе)

const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;

void dfs(int cur_moneybox) {           /// Обход графа в глубину для поиска циклов
    color[cur_moneybox] = GREY;
    for (int i = 0; i < moneyboxes.size(); i++) {
        if (moneyboxes[i] == cur_moneybox) {
            if (color[i] == WHITE)
                dfs(i);
            if (color[i] == GREY)
                min_broken++;
        }
    }
    color[cur_moneybox] = BLACK;
}

int main() {
    int N;                             /// кол-во копилок
    cin >> N;
    color.resize(N, WHITE);
/// Заполнение графа
    for (int i = 0; i < N; i++) {
        int key;
        cin >> key;
        moneyboxes.push_back(key - 1);
    }
/// Обход всех вершин (поиск циклов)
    for (int i = 0; i < N; i++) {
        if (color[i] == WHITE)
            dfs(i);
    }
    cout << min_broken;
    return 0;
}