#include <stdio.h>

int table[100][100];

int main(void) {
    int N;
    scanf("%d", &N);
    if (N > 100 || N < 2) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    if (table[0][0] < table[0][1] && table[0][0] < table[1][0]) {
        // left-top
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", table[i][j]);
                if (j != N - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else if (table[N-1][0] < table[N-1][1] && table[N-1][0] < table[N-2][0]) {
        // left-bottom
        for (int j = 0; j < N; j++) {
            for (int i = N - 1; i >= 0; i--) {
                printf("%d", table[i][j]);
                if (i != 0) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else if (table[0][N-1] < table[0][N-2] && table[0][N-1] < table[1][N-1]) {
        // right-top
        for (int j = N - 1; j >= 0; j--) {
            for (int i = 0; i < N; i++) {
                printf("%d", table[i][j]);
                if (i != N - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else {
        // right-bottom
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                printf("%d", table[i][j]);
                if (j != 0) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
