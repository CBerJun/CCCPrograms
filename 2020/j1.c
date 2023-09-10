#include <stdio.h>

int main() {
    int S, M, L;
    scanf("%d", &S);
    scanf("%d", &M);
    scanf("%d", &L);
    if (S + 2 * M + 3 * L >= 10) {
        printf("happy");
    }
    else {
        printf("sad");
    }
    return 0;
}
