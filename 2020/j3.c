#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int x_min = 100, x_max = 0, y_min = 100, y_max = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d", &x);
        getchar();  // ','
        scanf("%d", &y);
        if (x <= x_min) {
            x_min = x - 1;
        }
        if (x >= x_max) {
            x_max = x + 1;
        }
        if (y <= y_min) {
            y_min = y - 1;
        }
        if (y >= y_max) {
            y_max = y + 1;
        }
    }
    printf("%d,%d\n", x_min, y_min);
    printf("%d,%d", x_max, y_max);
    return 0;
}
