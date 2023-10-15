#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_DIGITS 5

int main(void) {
    int x;
    scanf("%d", &x);
    for (int i = x + 1; ; i++) {
        int cur = i;
        bool succ = true;
        bool digit_seen[10];
        bool skipped_0 = false;
        for (int j = 0; j < 10; j++) {
            digit_seen[j] = false;
        }
        for (int j = MAX_DIGITS - 1; j >= 0; j--) {
            int j10 = (int) pow(10, j);
            int digit = cur / j10;
            if (digit != 0) {
                skipped_0 = true;
            }
            if (digit_seen[digit]) {
                succ = false;
                break;
            }
            if (digit != 0 || skipped_0) {
                digit_seen[digit] = true;
            }
            cur -= digit * j10;
        }
        if (succ) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
