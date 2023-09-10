/*
 * This is my answer... Brute force, yeah
 * 10/15 scores
 */

/*
#include <stdio.h>

#define MAX_M 100
#define MAX_N 100

char table[MAX_M][MAX_N];

void invert(char *x) {
    if (*x == 'B') {
        *x = 'G';
    }
    else {
        *x = 'B';
    }
}

int main() {
    int M, N, K;
    scanf("%d", &M);
    scanf("%d", &N);
    scanf("%d", &K);
    if (M > MAX_M || N > MAX_N) {
        return 1;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            table[i][j] = 'B';
        }
    }
    for (int i = 0; i < K; i++) {
        char choice;
        int value;
        getchar();  // '\n'
        scanf("%c", &choice);
        getchar();  // ' '
        scanf("%d", &value);
        value--;
        if (choice == 'R') {
            for (int i = 0; i < N; i++) {
                invert(&table[value][i]);
            }
        }
        else {  // if choice == 'C'
            for (int i = 0; i < M; i++) {
                invert(&table[i][value]);
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 'G') {
                sum++;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
*/

/*
 * Algorithm from commentary
 * NOT THAT HARD actually...
 * Cell at (r, c) is Black if ((operations on r) + (operations on c))%2==0,
 * or else it's Gold.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N, K;
    scanf("%d", &M);
    scanf("%d", &N);
    scanf("%d", &K);
    int *rows = malloc(sizeof(int[M]));
    int *cols = malloc(sizeof(int[N]));
    for (int i = 0; i < M; i++) {
        rows[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        cols[i] = 0;
    }
    for (int i = 0; i < K; i++) {
        char choice;
        int value;
        getchar();  // '\n'
        scanf("%c", &choice);
        getchar();  // ' '
        scanf("%d", &value);
        value--;
        if (choice == 'R') {
            rows[value]++;
        }
        else {  // if choice == 'C'
            cols[value]++;
        }
    }
    int gold_count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if ((rows[i] + cols[j]) % 2 == 1) {
                gold_count++;
            }
        }
    }
    free(rows);
    free(cols);
    printf("%d\n", gold_count);
    return 0;
}
