#include <stdio.h>

int main(void) {
    int n;
    int a = 100, d = 100;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a0, d0;
        scanf("%d %d", &a0, &d0);
        if (a0 > d0) {
            d -= a0;
        }
        else if (a0 < d0) {
            a -= d0;
        }
    }
    printf("%d\n%d\n", a, d);
    return 0;
}
