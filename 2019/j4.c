#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void) {
    char cur = getchar();
    bool h = false, v = false;
    while (cur != '\n') {
        if (cur == 'H') {
            h = !h;
        }
        else {
            // cur == 'V'
            v = !v;
        }
        cur = getchar();
    }
    int grid[] = {
        1, 2,
        3, 4
    };
    int tmp;
    if (h) {
        swap(&grid[0], &grid[2]);
        swap(&grid[1], &grid[3]);
    }
    if (v) {
        swap(&grid[0], &grid[1]);
        swap(&grid[2], &grid[3]);
    }
    printf("%d %d\n%d %d\n", grid[0], grid[1], grid[2], grid[3]);
    return 0;
}
