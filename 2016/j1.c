#include <stdio.h>

#define GAMES 6

int main(void) {
    int loses = 0;
    for (int i = 0; i < GAMES; i++) {
        loses += getchar() == 'L';
        getchar();  // '\n'
    }
    int res;
    switch (loses) {
        case 0:
        case 1:
            res = 1;
            break;
        case 2:
        case 3:
            res = 2;
            break;
        case 4:
        case 5:
            res = 3;
            break;
        default:
            res = -1;
    }
    printf("%d\n", res);
    return 0;
}
