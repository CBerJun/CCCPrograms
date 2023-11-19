#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Pos;
typedef pair<Pos, int> Task;

const Pos MOVES[] = {
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
};
const int WIDTH = 8, HEIGHT = 8;
bool queued[WIDTH][HEIGHT];

int main() {
    Task init;
    Pos dest;
    cin >> dest.first >> dest.second
        >> init.first.first >> init.first.second;
    init.second = 0;
    init.first.first -= 1;  // 1-indexed...
    init.first.second -= 1;
    dest.first -= 1;
    dest.second -= 1;
    queued[init.first.first][init.first.second] = true;
    queue<Task> tasks;
    tasks.push(init);
    while (true) {
        // if (tasks.empty()) {
        //     printf("impossible\n");
        //     break;
        // }
        Task cur = tasks.front();
        tasks.pop();
        if (cur.first == dest) {
            printf("%d\n", cur.second);
            break;
        }
        // printf("%d %d,%d\n", tasks.size(),
        //        cur.first.first, cur.first.second);
        for (int i = 0; i < sizeof(MOVES) / sizeof(MOVES[0]); i++) {
            Pos next = {
                cur.first.first + MOVES[i].first,
                cur.first.second + MOVES[i].second
            };
            if (next.first < 0 || next.first >= WIDTH
                || next.second < 0 || next.second >= HEIGHT) {
                continue;
            }
            if (queued[next.first][next.second]) {
                continue;
            }
            queued[next.first][next.second] = true;
            tasks.push(make_pair(next, cur.second + 1));
        }
    }
    return 0;
}
