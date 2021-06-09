#include <iostream>
#include <algorithm>
using namespace std;

int max_p2 (int x) {                    /// Поиск степени двойки, ближайшей сверху к заданному числу
    int p2 = 1;
    while (true) {
        if (p2 >= x) return p2;
        p2 = p2 << 1;
    }
}
void treeBuild(int* array, int* tree, const int size) {   /// Построение дерева отрезков (снизу)
    for (int i = 0; i < size; i++)
        tree[size - 1 + i] = array[i];                    /// Запишем исходную послед-ть (в конец дерева)
    for (int i = size-2; i >= 0; i--)                     /// Поднимаемся от листьев к корню
        tree[i] = min(tree[2*i + 1], tree[2*i + 2]);      /// Заполняем дерево
}
int segm_MIN(int* tree, int left, int right) {            /// Поиск минимума на отрезке
    int leftRes = INT32_MAX, rightRes = INT32_MAX;
    while (left < right) {
        if (left % 2 == 0)                                /// Эл-т, попавший на левую границу, явл. правым сыном
            leftRes = min(leftRes, tree[left]);
        left /= 2;
        if (right % 2 == 1)                               /// Эл-т на правой границе - левый сын ?
            rightRes = min(tree[right], rightRes);
        right = right / 2 - 1;
    }
    if (left == right)
        leftRes = min(leftRes, tree[left]);
    return min(leftRes, rightRes);
}

int main() {
    int N, K;                                           /// N - длина послед-ти, K - длина "окна"
    cin >> N >> K;
    const int size = (const int) max_p2(N);             /// увеличиваем размер массива до 2^k >= N

    int* array = new int[size];                         /// array - исходная последовательность
    for (int i = 0; i < size; i++) {
        if (i < N)
            cin >> array[i];
        else array[i] = INT32_MAX;                      /// Дозаполним массив до 2^k максимальными значениями
    }

    int* tree = new int[(size << 1) - 1];               /// Segment_tree (дерево отрезков)
    treeBuild(array, tree, size);

    int left = size-1, right = size-1 + K-1;            /// left - левая, right - правая граница "окна"
    for (int i = 0; i < N-K+1; i++) {
        cout << segm_MIN(tree, left, right) << ' ';
        left++; right++;
    }
    delete (array);
    delete (tree);
    return 0;
}
