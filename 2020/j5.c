/* 13/15 (probably)
 * Test j5.07.02, 05, 06, 07 crash the program, probably due to call
 * stack overflow. Other tests run as expected.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int find(int M, int N, int table[M][N], int i, int j, bool seen[M][N]) {
    if (i >= M || j >= N) {
        return 0;
    }
    if (seen[i][j]) {
        return 0;
    }
    if (i == M - 1 && j == N - 1) {
        return 1;
    }
    // printf("enter i, j, seen: %d, %d, %d\n", i, j, seen[i][j]);
    int value = table[i][j];
    int p1 = 1;
    seen[i][j] = true;
    while (p1 <= ceil(sqrt(value))) {
        div_t d = div(value, p1);
        if (d.rem == 0) {
            if (find(M, N, table, p1 - 1, d.quot - 1, seen)
                || find(M, N, table, d.quot - 1, p1 - 1, seen)) {
                return 1;
            }
        }
        p1++;
    }
    // printf("exit i, j: %d, %d\n", i, j);
    return 0;
}

int main() {
    int M, N;
    scanf("%d", &M);
    scanf("%d", &N);
    int (*table)[N] = malloc(sizeof(int[M][N]));
    bool (*seen)[N] = malloc(sizeof(bool[M][N]));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &table[i][j]);
            seen[i][j] = false;
        }
    }
    printf("%s\n", find(M, N, table, 0, 0, seen) ? "yes" : "no");
    free(table);
    free(seen);
    return 0;
}
