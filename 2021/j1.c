#include <stdio.h>

int main() {
    int B, P;
    scanf("%d", &B);
    P = 5 * B - 400;
    printf("%d\n", P);
    if (P == 100) {
        printf("0\n");
    }
    else if (P > 100) {
        printf("-1\n");
    }
    else {
        printf("1\n");
    }
    return 0;
}
