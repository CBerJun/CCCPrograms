#include <stdio.h>

#define S 3

const char pattern[S][S] = {
    {'*', 'x', '*'},
    {' ', 'x', 'x'},
    {'*', ' ', '*'}
};

int main(void) {
    int s;
    scanf("%d", &s);
    for (int i = 0; i < S * s; i++) {
        for (int j = 0; j < S * s; j++) {
            putchar(pattern[i / s][j / s]);
        }
        putchar('\n');
    }
    return 0;
}
