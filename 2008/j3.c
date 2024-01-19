#include <stdio.h>
#include <math.h>

void locate(char ch, int *x, int *y) {
    switch (ch) {
    case ' ':
        *x = 2; *y = 4;
        break;
    case '-':
        *x = 3; *y = 4;
        break;
    case '.':
        *x = 4; *y = 4;
        break;
    default:
        ch -= 'A';
        *x = ch % 6;
        *y = ch / 6;
    }
}

int main(void) {
    char ch;
    int x = 0, y = 0;
    int nx, ny;
    int res = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        locate(ch, &nx, &ny);
        res += abs(x - nx) + abs(y - ny);
        x = nx; y = ny;
    }
    res += 9 - x - y;
    printf("%d\n", res);
    return 0;
}
