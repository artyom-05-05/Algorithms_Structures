#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> G;                      /// граф G

bool isBipartite(int N) {                   /// Проверка: является ли данный граф двудольным
    vector<int> colorArr(N);                /// массив для хранения цветов (1 - первый цвет, 0 - второй цвет)

    for (int i = 0; i < N; i++)             /// изначально все вершины не окрашены
        colorArr[i] = -1;

    for (int i = 0; i < N; i++) {           /// Произведём серию поисков в ширину
        if (colorArr[i] == -1) {            /// будем запускать поиск в ширину из каждой непосещённой вершины
            colorArr[i] = 1;                /// стартовой вершине назначаем первый цвет

            queue<int> q;                   /// создаем очередь для обхода графа в ширину
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v = 0; v < N; v++) {                           /// Переберем все неокрашенные смежные вершины
                    if (G[u][v] && colorArr[v] == -1) {
                        colorArr[v] = 1 - colorArr[u];                 /// Смежной вершине присваиваем альтернативный цвет
                        q.push(v);
                    }
                    else if (G[u][v] && colorArr[v] == colorArr[u])    /// Если соседняя вершина окрашена тем же цветом
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N, M;                           /// N - кол-во лкшат, M - кол-во пар
    cin >> N >> M;

    G.resize(N);
    for (int i = 0; i < N; i++)
        G[i].resize(N, 0);

/// Заполнение графа
    for (int k = 0; k < M; k++) {
        int i, j;
        cin >> i >> j;
        G[i-1][j-1] = 1;
        G[j-1][i-1] = 1;
    }
    isBipartite(N) ? cout << "YES" : cout << "NO";
    return 0;
}