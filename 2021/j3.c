#include <stdio.h>
#include <string.h>

int main() {
    char dir1, dir2;
    int step;
    char last[10];
    while (1) {
        scanf("%c%c%d", &dir1, &dir2, &step);
        getchar();  // '\n'
        dir1 -= '0';
        dir2 -= '0';
        if (dir1 == 9 && dir2 == 9 && step == 999) {
            break;
        }
        int sum = dir1 + dir2;
        if (sum % 2 == 1) {
            strcpy(last, "left");
        }
        else if (sum != 0) {
            strcpy(last, "right");
        }
        printf("%s %d\n", last, step);
    }
    return 0;
}
