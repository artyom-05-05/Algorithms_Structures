#include <iostream>
#include <vector>
using namespace std;

struct Sign {
    int index;
    int quantity;
};

pair<int, int> choose_pair(vector<Sign> signs, int k) {
    pair<int, int> cur_pair = make_pair(0, 0);
    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < k; i++) {
        if (signs[i].quantity > 0) {
            if (signs[i].quantity >= max) {
                max = signs[i].quantity;
                cur_pair.first = i;
            }
            if (signs[i].quantity < min) {
                min = signs[i].quantity;
                cur_pair.second = i;
            }
        }
    }
    return cur_pair;
}

int main() {
    int k, total_quantity = 0;
    cin >> k;

    vector<Sign> signs(k);
    for (int i = 0; i < k; i++) {
        cin >> signs[i].quantity;
        signs[i].index = i + 1;
        total_quantity += signs[i].quantity;
    }

    pair<int, int> cur_pair;

    while (total_quantity > 0) {
        cur_pair = choose_pair(signs, k);

        if (signs[cur_pair.first].quantity > 0) {
            cout << signs[cur_pair.first].index << " ";
            signs[cur_pair.first].quantity--;
            total_quantity--;
        }

        if (signs[cur_pair.second].quantity > 0) {
            cout << signs[cur_pair.second].index << " ";
            signs[cur_pair.second].quantity--;
            total_quantity--;
        }
    }
    return 0;
}