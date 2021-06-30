#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct exchange_point {
    int A;
    int B;
    double rate;
    double commission;
};

int main() {
    int N, M, S;            /// N - кол-во валют, M - кол-во обменных пунктов, S - №валюты у Ника
    double V;               /// V - кол-во денеж.ед.
    cin >> N >> M >> S >> V;
/// Ввод данных о обменных пунктах
    vector<struct exchange_point> exc_points;
    int A1, B1;
    double RAB, CAB, RBA, CBA;
    for (int i = 0; i < M; i++) {
        cin >> A1 >> B1 >> RAB >> CAB >> RBA >> CBA;
        exc_points.push_back({A1-1, B1-1, RAB, CAB});
        exc_points.push_back({B1-1, A1-1, RBA, CBA});
    }
/// Алгоритм поиска по графу (Форд_Беллман)
    vector<double> currency(N, 0);
    currency[S-1] = V;
    for (int i = 0; i < currency.size(); i++) {
        for (auto p: exc_points) {
            currency[p.B] = max((currency[p.A] - p.commission) * p.rate, currency[p.B]);
        }
    }
/// Вывод (сможет ли Ник увеличить свой капитал)
    for (auto p: exc_points) {
        if ((currency[p.A] - p.commission) * p.rate > currency[p.B]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
