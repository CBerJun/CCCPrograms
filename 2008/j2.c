#include <stdio.h>
#include <string.h>

int main(void) {
    int op, n;
    char tmp[5];
    char l[5] = {'A', 'B', 'C', 'D', 'E'};
    while (1) {
        scanf("%d %d", &op, &n);
        if (op == 2) {
            op = 1;
            n = 5 - n % 5;
        }
        if (op == 1) {
            n %= 5;
            memcpy(tmp, l, 5);
            memcpy(l + 5 - n, tmp, n);
            memcpy(l, tmp + n, 5 - n);
        }
        if (op == 3 && (n & 1)) {
            const char tmp = l[0];
            l[0] = l[1];
            l[1] = tmp;
        }
        if (op == 4) {
            printf("%c %c %c %c %c\n", l[0], l[1], l[2], l[3], l[4]);
            break;
        }
    }
    return 0;
}
