/* 00:18:40 */

#include <stdio.h>

int main() {
    char cur = getchar();
    while (cur != '\n') {
        while (cur != '+' && cur != '-') {
            printf("%c", cur);
            cur = getchar();
        }
        printf(" ");
        printf(cur == '+' ? "tighten" : "loosen");
        printf(" ");
        cur = getchar();
        while ('0' <= cur && cur <= '9') {
            printf("%c", cur);
            cur = getchar();
        }
        printf("\n");
    }
    return 0;
}
