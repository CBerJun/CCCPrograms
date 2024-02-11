/* I think about the three way partitioning algorithm.
   But it doesn't really make sense here because we want
   the most optimal solution. */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[500001];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int lidx = 0, midx = 0;
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'L':
                ++lidx;
            case 'M':
                ++midx;
        }
    }
    // printf("(%d %d)", lidx, midx);
    int lwants, lwantm,
        mwants, mwantl,
        swantm, swantl;
    int correct = 0;
    lwants = lwantm = mwants = mwantl = swantm = swantl = 0;
    for (int i = 0; i < lidx; ++i) {
        if (s[i] == 'L') {
            ++correct;
        }
        else if (s[i] == 'M') {
            ++mwantl;
        }
        else {
            ++swantl;
        }
    }
    for (int i = lidx; i < midx; ++i) {
        if (s[i] == 'L') {
            ++lwantm;
        }
        else if (s[i] == 'M') {
            ++correct;
        }
        else {
            ++swantm;
        }
    }
    for (int i = midx; i < n; ++i) {
        if (s[i] == 'L') {
            ++lwants;
        }
        else if (s[i] == 'M') {
            ++mwants;
        }
        else {
            ++correct;
        }
    }
    // printf("(%d %d %d %d %d %d)",
    //     lwants, lwantm, mwants, mwantl, swantm, swantl);
    int res = 0;
    int rem = n - correct;
    int tmp;
    tmp = min(swantm, mwants);
    res += tmp;
    rem -= tmp << 1;
    tmp = min(swantl, lwants);
    res += tmp;
    rem -= tmp << 1;
    tmp = min(mwantl, lwantm);
    res += tmp;
    rem -= tmp << 1;
    if (rem % 3) {
        // unreachable
        printf("-1\n");
    }
    else {
        printf("%d\n", res + ((rem / 3) << 1));
    }
}
