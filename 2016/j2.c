#include <stdio.h>

#define SIZE 4

int col_sums[SIZE];

int main(void) {
    int expected = -1;
    for (int i = 0; i < SIZE; i++) {
        int row_sum = 0;
        for (int j = 0; j < SIZE; j++) {
            int num;
            scanf("%d", &num);
            col_sums[j] += num;
            row_sum += num;
        }
        if (expected == -1) {
            expected = row_sum;
        }
        else if (expected != row_sum) {
            goto wrong;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (col_sums[i] != expected) {
            goto wrong;
        }
    }
    goto exit;
wrong:
    printf("not ");
exit:
    printf("magic\n");
    return 0;
}
