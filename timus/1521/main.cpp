#include <iostream>
using namespace std;

int soldier_num = 0;
struct Node {
    int cnt_down;               /// кол-во узлов ниже данного
    int bottom_el;              /// № солдата (если не нижний элемент, то 0)
    Node *left;
    Node *right;

    Node(int cnt, int soldier) {
        bottom_el = soldier;
        cnt_down = cnt;
        left = nullptr;
        right = nullptr;
    }
};

void buildTree(struct Node *root) {                         /// Бинарное дерево
    if (root->cnt_down >= 2) {
        root->left = new Node(root->cnt_down / 2, 0);
        buildTree(root->left);

        root->right = new Node(root->cnt_down - root->cnt_down / 2, 0);
        buildTree(root->right);
    }
    if (root->cnt_down == 1)
        root->left = new Node(0, ++soldier_num);
}

void remove_soldier(struct Node *root, int soldier_num) {        /// дойти до листа дерева + вывести номер солдата
    if (root->bottom_el) {
        cout << root->bottom_el << ' ';
        return;
    }

    if (root->left && (root->left->cnt_down >= soldier_num || root->left->bottom_el))
        remove_soldier(root->left, soldier_num);
    else if (root->right)
        remove_soldier(root->right, soldier_num - root->left->cnt_down);

    root->cnt_down--;                  /// изменим кол-во вершин в пройденной ветке
}

int main() {
    int n, k;
    cin >> n >> k;

    auto root = new Node(n, 0);
    buildTree(root);

    int soldier_for_del = 1;
    while (root->cnt_down) {
        soldier_for_del += k - 1;
        soldier_for_del = (soldier_for_del % root->cnt_down)? soldier_for_del % root->cnt_down : root->cnt_down;
        remove_soldier(root, soldier_for_del);
    }
}