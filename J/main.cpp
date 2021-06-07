#include <iostream>
#include <deque>
using namespace std;

deque <int> part1, part2;

int main() {
    int N, num;              /// N - кол-во запросов, num - номер гоблина
    char tag;                /// '+' добавляем в конец; '-' выходит первый; '*' встает в середину
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tag;
        switch (tag) {
            case '+':
                cin >> num;
                part2.push_back(num);
                if (part2.size() > part1.size()) {
                    part1.push_back(part2.front());
                    part2.pop_front();
                }
                break;
            case '-':
                cout << part1.front() << endl;
                part1.pop_front();
                if (part2.size() > part1.size()) {
                    part1.push_back(part2.front());
                    part2.pop_front();
                }
                break;
            case '*':
                cin >> num;
                part2.push_front(num);
                if (part2.size() > part1.size()) {
                    part1.push_back(part2.front());
                    part2.pop_front();
                }
                break;
            default:
                break;
        }
    }
    return 0;
}