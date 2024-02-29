#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int memo[76];
    memset(memo, 0, 76 * sizeof(int));
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        ++memo[t];
    }
    int c = 0;
    for (int i = 75; i >= 0; --i) {
        if (!memo[i]) continue;
        ++c;
        if (c == 3) {
            printf("%d %d\n", i, memo[i]);
            break;
        }
    }
    return 0;
}
