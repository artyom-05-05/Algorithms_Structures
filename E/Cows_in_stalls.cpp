#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> coords;

bool check(int min_dist) {
    int cows = 1;
    int last_cow = coords[0];
    for (int cur_coord: coords) {
        if (cur_coord - last_cow >= min_dist) {
            cows += 1;
            last_cow = cur_coord;
        }
    }
    return cows >= K;
}

int main() {
    cin >> N >> K;                          // Ввод кол-ва стойл N и кол-ва коров K
    int coord;
    for (int i = 0; i < N; i++) {           // Ввод массива координат стойл coord(N)
        cin >> coord;
        coords.emplace_back(coord);
    }
//Обработка
    int left = 0;
    int right = coords.back() - coords.front() + 1;
    int mean;

    while (left < right) {
        mean = (left + right) / 2;
            if (check(mean)) left = mean + 1;
        else right = mean;
    }
    right--;
//Вывод
    cout << right;
    return 0;
}