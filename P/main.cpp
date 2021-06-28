#include <iostream>
#include <vector>
using namespace std;

int N;                                    /// число городов
vector<vector<int>> map;                  /// карта, на которой отмечен расход топлива м/у городами
vector<bool> visited;

void dfs(int city, int reservoir, bool direct) {     /// Обход в глубину: прямой и обратный (bool direct)
    visited[city] = true;
    for (int i = 0; i < N; i++) {
        if (direct) {
            if (!visited[i] && reservoir >= map[city][i])
                dfs(i, reservoir, direct);
        }
        else {
            if (!visited[i] && reservoir >= map[i][city])
                dfs(i, reservoir, direct);
        }
    }
}

bool verify(int reservoir) {                    /// Проверка, хватит ли топлива, чтоб долететь из любого города в любой

    visited.assign(N, false);                   /// Прямая проверка
    dfs(0, reservoir, true);
    for (auto v: visited){
        if (!v) return false;
    }

    visited.assign(N, false);                   /// Обратная проверка
    dfs(0, reservoir, false);
    for (auto v: visited){
        if (!v) return false;
    }

    return true;
}

int main() {
    cin >> N;

/// Ввод карты (расход топлива для перелета м/у городами)
    visited.resize(N, false);
    map.resize(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
/// Бинарный поиск оптимального размера бака
    int l = 0, r = INT32_MAX, mid;          /// границы для бинарного поиска
    while (l < r) {
        mid = (l + r) / 2;

        if (verify(mid)) r = mid;           /// проверяем, какую часть нужно отбросить из поиска
        else l = mid + 1;
    }

    cout << l;
    return 0;
}
