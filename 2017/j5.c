/* Passing on first time I run it on testrunner!!! */

#include <stdio.h>

#define MAXL 2000
#define min(a, b) ((a) < (b) ? (a) : (b))

int woods[MAXL+1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        woods[l]++;
    }
    int ans = 0;
    int num = 0;
    for (int i = 2; i <= MAXL * 2; i++) {
        int cur = 0;
        /*
         * Suppose MAXL = 20
         * If i == 6,
         *   (j, i - j): (5, 1), (4, 2), (3, 3)
         *                5 is i - 1
         * If i == 7,
         *   (j, i - j): (6, 1), (5, 2), (4, 3)
         *                6 is i - 1
         * ...
         * If i == 22,
         *   (j, i - j): (20, 2), (19, 3), (18, 4), ...
         *                20 is MAXL
         * ...
         */
        for (int j = min(MAXL, i - 1); j >= i - j; j--) {
            // printf("%d %d %d %d\n", j, i - j, woods[j], woods[i - j]);
            if (j == (i - j)) {
                cur += woods[j] / 2;
            }
            else {
                cur += min(woods[j], woods[i - j]);
            }
        }
        // printf("Cur: %d\n", cur);
        if (cur > ans) {
            ans = cur;
            num = 1;
        }
        else if (cur == ans) {
            num++;
        }
    }
    printf("%d %d\n", ans, num);
    return 0;
}
