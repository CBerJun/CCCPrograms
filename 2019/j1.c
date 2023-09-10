#include <stdio.h>

int main(void) {
    int a1, a2, a3;
    int b1, b2, b3;
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &a3);
    scanf("%d", &b1);
    scanf("%d", &b2);
    scanf("%d", &b3);
    int a = 3 * a1 + 2 * a2 + 1 * a3;
    int b = 3 * b1 + 2 * b2 + 1 * b3;
    if (a > b) {
        printf("A");
    }
    else if (a < b) {
        printf("B");
    }
    else {
        printf("T");
    }
    printf("\n");
    return 0;
}
