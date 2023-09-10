#include <stdio.h>

int main(void) {
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    if ((a == 8 || a == 9)
        && (d == 8 || d == 9)
        && b == c) {
        printf("ignore\n");
    }
    else {
        printf("answer\n");
    }
    return 0;
}
