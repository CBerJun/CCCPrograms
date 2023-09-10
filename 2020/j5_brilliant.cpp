/*
 * Brilliant solution!
 * It can be difficult to calculate factor, so we do it backwards!
 * Search from (M, N) to (0, 0).
 * At cell (r, c), we just need to find cells with value r * c --
 * without factoring!
 */

#include <bits/stdc++.h>

class Cell {
public:
    int r, c;
};

const int MAX = 1008;
bool seen[MAX][MAX];
std::vector<Cell> product2cells[MAX * MAX];

int main() {
    int M, N;
    scanf("%d", &M);
    scanf("%d", &N);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int value;
            Cell cell;
            scanf("%d", &value);
            cell.r = i;
            cell.c = j;
            product2cells[value].push_back(cell);
        }
    }
    // BFS
    std::deque<Cell> tasks;
    Cell begin;
    begin.r = M;
    begin.c = N;
    tasks.push_back(begin);
    while (!tasks.empty()) {
        Cell c = tasks.front();
        tasks.pop_front();
        // std::cout << "Task: " << c.r << " " << c.c << std::endl;
        for (Cell next : product2cells[c.r * c.c]) {
            // std::cout << " Next: " << next.r << " " << next.c << std::endl;
            if (next.c == 1 && next.r == 1) {
                printf("yes\n");
                return 0;
            }
            if (!seen[next.r][next.c]) {
                seen[next.r][next.c] = true;
                tasks.push_back(next);
            }
        }
    }
    printf("no\n");
    return 0;
}
