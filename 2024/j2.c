#include <stdio.h>

int main(void) {
    int r, t;
    scanf("%d", &r);
    while (scanf("%d", &t)) {
        if (t >= r) {
            break;
        }
        r += t;
    }
    printf("%d\n", r);
    return 0;
}
