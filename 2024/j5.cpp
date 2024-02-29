#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

char *f;
int r, c;

inline int judge(char x) {
    if (x == 'S') return 1;
    else if (x == 'M') return 5;
    else return 10;
}

int main() {
    scanf("%d %d", &r, &c);
    const int pmax = r * c;
    f = (char*) malloc(sizeof(char) * (pmax + 1));  // +1 for \0
    for (int i = 0; i < pmax; i += c) {
        scanf("%s", f + i);
    }
    int si, sj;
    scanf("%d %d", &si, &sj);
    const int offset[4] = {1, -1, c, -c};

    int s = si * c + sj;
    queue<int> q;  // queue of gpos
    int res = judge(f[s]);
    q.push(s);
    f[s] = '*';
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        const int col = p % c;
        for (int i = 0; i < 4; ++i) {
            if ((i == 0 && col == c-1) || (i == 1 && col == 0)) continue;
            const int np = p + offset[i];
            if (0 <= np && np < pmax && f[np] != '*') {
                res += judge(f[np]);
                f[np] = '*';
                q.push(np);
            }
        }
    }

    printf("%d\n", res);
    free(f);
    return 0;
}
