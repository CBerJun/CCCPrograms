#include <stdio.h>
#include <math.h>

int main(void) {
    int h, m;
    scanf("%d", &h);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        if ((-6 * pow(i, 4) + h * pow(i, 3) + 2 * pow(i, 2) + i) <= 0) {
            printf("The balloon first touches ground at hour:\n");
            printf("%d\n", i);
            goto exit;
        }
    }
    printf("The balloon does not touch ground in the given time.\n");
exit:
    return 0;
}
