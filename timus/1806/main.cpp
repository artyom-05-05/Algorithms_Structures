#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <deque>
using namespace std;
const int INF = INT32_MAX;

int N;                                       /// N - кол-во бойцов в дивизии
int sending_time[10];                        /// время передачи сообщения (в завис-ти от длины общего префикса их номеров)
vector<string> telegraphs;                   /// номера телеграфов
vector<deque<pair<int, int>>> connections;   /// устойчивые связи м/у солдатами (ребра графа)

bool check_connection(int a, int b) {
    int err_cnt = 0;                         /// кол-во ошибок
    pair<char,char> errs[2];
    for (int i = 0; i < 10; i++) {
        if (telegraphs[a][i] != telegraphs[b][i]) {
            if (err_cnt < 2)
                errs[++err_cnt - 1] = {telegraphs[a][i], telegraphs[b][i]};
            else return false;
        }
    }
    if (err_cnt == 2) {
        swap(errs[1].first, errs[1].second);
        if (errs[0] == errs[1]) return true;
        else return false;
    }
    return true;
}

int calculate_sending_time(int a, int b) {
    for (int i = 0; i < 10; i++) {
        if (telegraphs[a][i] == telegraphs[b][i])
            continue;
        else return sending_time[i];
    }
}

void build_graph() {
    connections.resize(N);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (check_connection(i, j)) {
                int time = calculate_sending_time(i, j);
                connections[i].push_back(make_pair(j, time));
                connections[j].push_back(make_pair(i, time));
            }
        }
    }
}

vector<int> d, p;                       /// d - кратчайшие расстояния, p - массив предков
set<pair<int, int>> q;                  /// q = {(расстояние - вершина)}

bool dijkstra() {
    if (connections.empty()) return false;
    d.assign(N, INF);
    p.resize(N);

    int start = 0;
    d[start] = 0;
    q.insert(make_pair(d[start], start));

    while (!q.empty()) {
        int v = q.begin()->second;                  /// вершина с наименьшим расстоянием
        q.erase(q.begin());

        for (auto neighbor: connections[v]) {
            int to = neighbor.first;
            int w = neighbor.second;

            if (d[v] + w < d[to]) {                 /// Релаксация вершин
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + w;
                p[to] = v;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    return d[N-1] != INF;                           /// true = найден путь до последней вершины (сообщение передано)
}

int main() {
/// Ввод
    cin >> N;
    for (int i = 0; i < 10; i++)
        cin >> sending_time[i];

    for (int i = 0; i < N; i++) {
        string num;
        cin >> num;
        telegraphs.push_back(num);
    }
/// Построение графа (обработка номеров телеграфов)
    build_graph();
/// Поиск min времени на доставку сообщения + вывод
    if (dijkstra()) {
        int soldier_num = N - 1;
        stack<int> route;               /// LIFO

        while (soldier_num != 0) {
            route.push(soldier_num + 1);
            soldier_num = p[soldier_num];
        }
        cout << d[N-1] << endl << (route.size() + 1) << endl << 1;

        while (!route.empty()) {
            cout << ' ' << route.top();
            route.pop();
        }
    }
    else cout << -1;

    return 0;
}