#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct day {
    int x;          /// номер недели
    int y;          /// номер дня
};

bool compare_rows (struct day a, struct day b) {
    if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
}
bool compare_columns (struct day a, struct day b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int m, n, k;                 /// m*n - размеры календаря, k - кол-во неудачных дней
    cin >> m >> n >> k;
/// Ввод неудачных дней
    vector<struct day> unlucky_days;
    for (int i = 0; i < k; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        unlucky_days.push_back({x1,y1});
    }
/// Добавление рамки календаря
    for (int i = 1; i <= n; i++) {                    //  --------
        unlucky_days.push_back({0, i});               // -        -
        unlucky_days.push_back({m+1, i});             // -        -
    }                                                 // -        -
    for (int i = 1; i <= m; i++) {                    //  --------
        unlucky_days.push_back({i, 0});
        unlucky_days.push_back({i, n+1});
    }

    int counter = 0;                            /// кол-во белых полос
    set<struct day, decltype(compare_rows)*> single_cells(compare_rows); /// одиночные клетки (сохраняем для дальнейшей проверки)
/// Подсчёт белых строк
    sort(unlucky_days.begin(), unlucky_days.end(), compare_rows);
    for (int i = 1; i < unlucky_days.size(); i++) {
        if (unlucky_days[i-1].x == unlucky_days[i].x) {
            if ((unlucky_days[i].y - unlucky_days[i-1].y) > 2)
                counter++;
            if ((unlucky_days[i].y - unlucky_days[i-1].y) == 2)
                single_cells.insert({unlucky_days[i].x, unlucky_days[i].y - 1});
        }
    }
/// Подсчёт белых столбцов
    sort(unlucky_days.begin(), unlucky_days.end(), compare_columns);
    for (int i = 1; i < unlucky_days.size(); i++) {
        if (unlucky_days[i-1].y == unlucky_days[i].y) {
            if ((unlucky_days[i].x - unlucky_days[i-1].x) > 2)
                counter++;
            if ((unlucky_days[i].x - unlucky_days[i-1].x) == 2 &&
                single_cells.count({unlucky_days[i].x - 1, unlucky_days[i].y}))
                counter++;
        }
    }
    cout << counter;
    return 0;
}