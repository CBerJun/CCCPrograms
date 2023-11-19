#include <stdio.h>

int main(void) {
    int x, a;
    scanf("%d", &x);
    switch (x) {
        case 1:
        case 9:
        case 10:
            a = 1;
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            a = 2;
            break;
        case 4:
        case 5:
        case 6:
            a = 3;
            break;
    }
    printf("%d\n", a);
    return 0;
}
