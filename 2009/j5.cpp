#include <cstdio>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

unordered_set<int> g[50] = {
    {},
    {6},  // 1
    {6},  // 2
    {6, 4, 5, 15},  // 3
    {3, 5, 6},  // 4
    {3, 4, 6},  // 5
    {1, 2, 3, 4, 5, 7},  // 6
    {6, 8},  // 7
    {7, 9},  // 8
    {8, 10, 12},  // 9
    {9, 11},  // 10
    {10, 12},  // 11
    {9, 11, 13},  // 12
    {12, 14, 15},  // 13
    {13},  // 14
    {3, 13},  // 15
    {17, 18},  // 16
    {16, 18},  // 17
    {16, 17},  // 18
};

int main() {
    char op;
    int ax, bx;
    while (true) {
        scanf(" %c", &op);
        if (op == 'q') {
            break;
        }
        if (op == 'i') {
            scanf("%d %d", &ax, &bx);
            g[ax].insert(bx);
            g[bx].insert(ax);
        }
        if (op == 'd') {
            scanf("%d %d", &ax, &bx);
            g[ax].erase(bx);
            g[bx].erase(ax);
        }
        if (op == 'n') {
            scanf("%d", &ax);
            printf("%d\n", g[ax].size());
        }
        if (op == 'f') {
            scanf("%d", &ax);
            unordered_set<int> seen;
            seen.insert(ax);
            seen.insert(g[ax].begin(), g[ax].end());
            for (int i : g[ax]) {
                seen.insert(g[i].begin(), g[i].end());
            }
            printf("%d\n", seen.size() - 1 - g[ax].size());
        }
        if (op == 's') {
            scanf("%d %d", &ax, &bx);
            queue<pair<int, int>> q;
            unordered_set<int> seen;
            bool found = false;
            q.push(make_pair(ax, 0));
            seen.insert(ax);
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first == bx) {
                    printf("%d\n", cur.second);
                    found = true;
                    break;
                }
                for (int i : g[cur.first]) {
                    if (seen.find(i) != seen.end()) {
                        continue;
                    }
                    seen.insert(i);
                    q.push(make_pair(i, cur.second + 1));
                }
            }
            if (!found) {
                printf("Not connected\n");
            }
        }
    }
}
