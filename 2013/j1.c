#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d\n", y + (y - x));
    return 0;
}
