#include <stdio.h>

int data[20];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        if (n == 1) {
            scanf("%*d");
            printf("0\n");
            continue;
        }
        int last, cur;
        scanf("%d", &last);
        int cycle = 1;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d", &cur);
            data[i] = cur - last;
            if (data[i % cycle] != data[i]) {
                cycle = i + 1;
            }
            last = cur;
        }
        printf("%d\n", cycle);
    }
    return 0;
}
