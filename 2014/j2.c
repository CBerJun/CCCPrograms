#include <stdio.h>

int main(void) {
    int a = 0, b = 0, n;
    scanf("%d", &n);
    getchar();  // '\n'
    for (int i = 0; i < n; i++) {
        char v = getchar();
        if (v == 'A') {
            a++;
        }
        else if (v == 'B') {
            b++;
        }
    }
    if (a > b) {
        printf("A");
    }
    else if (a < b) {
        printf("B");
    }
    else {
        printf("Tie");
    }
    printf("\n");
    return 0;
}
