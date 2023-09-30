#include <stdio.h>

int main(void) {
    int m, d;
    scanf("%d", &m);
    scanf("%d", &d);
    if (m > 2) {
        printf("After\n");
    }
    else if (m == 1) {
        printf("Before\n");
    }
    else {
        if (d > 18) {
            printf("After\n");
        }
        else if (d == 18) {
            printf("Special\n");
        }
        else {
            printf("Before\n");
        }
    }
    return 0;
}
