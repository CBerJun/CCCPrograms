#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

char t[100][100];
char s[100];
const pair<int, int> OFFSETS[] = {
    // row, col
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0},
    {1, 1}, {-1, -1},
    {-1, 1}, {1, -1}
};
const pair<int, int> TURNS[] = {
    {2, 3}, {2, 3},
    {0, 1}, {0, 1},
    {6, 7}, {6, 7},
    {4, 5}, {4, 5}
};

inline bool out_of_bounds(int i, int j, int r, int c) {
    return i < 0 || i >= r || j < 0 || j >= c;
}

int main() {
    int lens = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        s[lens++] = ch;
    }
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> t[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 8; ++k) {
                const pair<int, int>& t_ofs1 = OFFSETS[TURNS[k].first];
                const pair<int, int>& t_ofs2 = OFFSETS[TURNS[k].second];
                const pair<int, int>& ofs = OFFSETS[k];
                // printf("(ij=%d,%d;ofs=%d,%d;t1=%d,%d;t2=%d,%d)\n",
                //     i, j, ofs.first, ofs.second, t_ofs1.first, t_ofs1.second,
                //     t_ofs2.first, t_ofs2.second);
                int ti = i, tj = j;
                for (int m = 0; m < lens; ++m) {
                    if (t[ti][tj] != s[m]) {
                        break;
                    }
                    int ti2 = ti, tj2 = tj;
                    // Try to turn
                    if (!m) {
                        // Can't just turn at (i, j)
                        goto n2;
                    }
                    for (int p = m + 1; p < lens; ++p) {
                        ti2 += t_ofs1.first;
                        tj2 += t_ofs1.second;
                        if (out_of_bounds(ti2, tj2, r, c) || t[ti2][tj2] != s[p]) {
                            goto n1;
                        }
                    }
                    // printf("(found ij=%d,%d; m=%d; ofs=%d,%d; t1=%d,%d;)\n",
                    //     i, j, m, ofs.first, ofs.second, t_ofs1.first, t_ofs1.second);
                    ++res;
                    if (m == lens - 1) {
                        goto n2;
                        // We are actually not rotating in this case
                        // (on a single line segment), so t2 would count +1
                        // again. We skip it here.
                    }
n1:
                    ti2 = ti; tj2 = tj;
                    for (int p = m + 1; p < lens; ++p) {
                        ti2 += t_ofs2.first;
                        tj2 += t_ofs2.second;
                        if (out_of_bounds(ti2, tj2, r, c) || t[ti2][tj2] != s[p]) {
                            goto n2;
                        }
                    }
                    // printf("(found ij=%d,%d; m=%d; ofs=%d,%d; t2=%d,%d;)\n",
                    //     i, j, m, ofs.first, ofs.second, t_ofs2.first, t_ofs2.second);
                    ++res;
n2:
                    ti += ofs.first;
                    tj += ofs.second;
                    if (out_of_bounds(ti, tj, r, c)) {
                        break;
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
