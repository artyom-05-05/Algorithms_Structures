#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <iterator>
using namespace std;

const int INF = 1000000;
const int FIELD = 1;
const int FOREST = 2;
const int WATER = -1;

struct cell {
    int type;           /// Индикатор пространства (поле, лес, вода)
    int time;           /// Время от начала до текущей ячейки (вес ячейки)
};

int N, M, MIN_time;     /// N - высота карты (кол-во строк), M - ширина карты (кол-во столбцов)
vector<vector<struct cell>> world_map;                        /// КАРТА мира
list<char> route;                                             /// Маршрут из (ax, ay) в (bx, by)

bool find_directions(int ax, int ay, int bx, int by) {        /// Поиск пути из (ax, ay) в (bx, by)
    int dx[4] = {1, 0, -1, 0};                                /// Смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1};                                /// справа, снизу, слева и сверху

    queue<pair<int, int>> changes;                            /// Создадим массив ячеек, изменивших вес
    world_map[ax][ay].time = 0;                               /// Пометим стартовую ячейку 0
    changes.push({ax, ay});

/// Распространение волны
    while (!changes.empty()) {
        pair<int, int> cur_cell = changes.front();
        changes.pop();
        int cur_time = world_map[cur_cell.first][cur_cell.second].time;  /// вес текущей ячейки

        for (int k = 0; k < 4; k++) {                         /// Проходим по всем соседям
            int ix = cur_cell.first + dx[k], iy = cur_cell.second + dy[k];
            if (ix >= 0 && ix < N && iy >= 0 && iy < M) {
                if (world_map[ix][iy].type != WATER && cur_time + world_map[ix][iy].type < world_map[ix][iy].time) {
                    world_map[ix][iy].time = cur_time + world_map[ix][iy].type;
                    changes.push({ix, iy});
                }
            }
        }

    }
    if (world_map[bx][by].time == INF) return false;         /// путь не найден

/// Восстановление пути
    MIN_time = world_map[bx][by].time;                       /// Время кратчайшего пути из (ax, ay) в (bx, by)
    int x = bx, y = by;

    while (world_map[x][y].time != 0) {
        for (int k = 0; k < 4; k++) {                        /// Проходим по всем соседям
            int ix = x + dx[k], iy = y + dy[k];
            if (ix >= 0 && ix < N && iy >= 0 && iy < M &&
                world_map[x][y].time - world_map[ix][iy].time == world_map[x][y].type) {
                x = ix;
                y = iy;                                      /// Переходим в ячейку, которая на 1 ближе к старту
                switch (k) {
                    case 0:
                        route.push_front('N');
                        break;
                    case 1:
                        route.push_front('W');
                        break;
                    case 2:
                        route.push_front('S');
                        break;
                    case 3:
                        route.push_front('E');
                        break;
                    default:
                        break;
                }
                break;
            }
        }
    }
    return true;
}

int main() {
    int ax, ay, bx, by;                    /// координаты начального и конечного положения
    cin >> N >> M >> ax >> ay >> bx >> by;

    /// Ввод карты
    world_map.resize(N);
    for (int i = 0; i < N; i++)
        world_map[i].resize(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char sym;
            cin >> sym;
            switch (sym) {
                case '.':
                    world_map[i][j] = {FIELD, INF};
                    break;
                case 'W':
                    world_map[i][j] = {FOREST, INF};
                    break;
                case '#':
                    world_map[i][j] = {WATER, INF};
                    break;
                default:
                    break;
            }
        }
    }
    /// Волновой алгоритм
    if (find_directions(ax - 1, ay - 1, bx - 1, by - 1)) {
        cout << MIN_time << endl;
//        for (int i = 0; i < N; i++) {                         /// Вывод карты
//            for (int j = 0; j < M; j++)
//                cout << world_map[i][j].time << ' ';
//            cout << endl;
//        }
        copy(route.begin(), route.end(), ostream_iterator<char>(cout,""));   /// Вывод маршрута
    }
    else cout << -1;

    return 0;
}