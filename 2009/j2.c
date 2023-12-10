#include <stdio.h>

int main(void) {
    int a, b, c, t, cnt = 0;
    scanf("%d %d %d %d", &a, &b, &c, &t);
    for (int i = 0; i <= t / a; i++) {
        for (int j = 0; j <= (t - i * a) / b; j++) {
            for (int k = 0; k <= (t - i * a - j * b) / c; k++) {
                if (i == j && j == k && k == 0) {
                    continue;
                }
                printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", i, j, k);
                ++cnt;
            }
        }
    }
    printf("Number of ways to catch fish: %d\n", cnt);
    return 0;
}
