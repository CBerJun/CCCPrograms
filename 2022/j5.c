/*
 * My idea:
 *   This problem is equivalent to:
 *     Given several squares (that may overlap), calculate the area of
 *     surface covered by all squares.
 * Actually...
 *   1. A tree split the area into four. Then add another tree and it
 *   split the subarea where it is in into another four...
 *   2. An identical square can be pushed up until upper boundary or
 *   a tree, and can be pushed left until left boundary or a tree.
 *   Thus, the identical rows for square's left-up corner can only be
 *   the row below tree 1, row below tree 2, ..., row below tree T, and
 *   row below upper boundary (same for columns!).
 * The below program uses approach 2. I hope it won't get TLE (C does
 * not have hash set).
 */

#include <stdio.h>

/*
struct I2d {
    int row;
    int col;
};

struct Area {
    struct I2d pos;
    int r;
    int c;
};

struct Seg {
    struct I2d
};

int area(struct Area a) {
    return a.r * a.c;
}

int main() {
    int M, T;
    struct I2d trees[T];
    scanf("%d", &M);
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &trees[i].row);
        scanf("%d", &trees[i].col);
        trees[i].row--;
        trees[i].col--;
    }
    for (int a = M; a >= 1; a--) {
        int M2 = M - a + 1;
        struct Area available;
        struct I2d origin = {0, 0};
        available.pos = origin;
        available.r = available.c = M2;
        struct Area tree_areas[T];
        for (int i = 0; i < T; i++) {
            tree_areas[i].pos = trees[i];
            tree_areas[i].r = tree_areas[i].c = a;
        }
        int occupied = 0;
    }
    return 0;
}
*/

struct I2d {
    int row;
    int col;
};

int main() {
    int N, T;
    scanf("%d", &N);
    scanf("%d", &T);
    struct I2d trees[T];
    for (int i = 0; i < T; i++) {
        scanf("%d", &trees[i].row);
        scanf("%d", &trees[i].col);
        trees[i].row--;
        trees[i].col--;
    }
    // Decide which rows and cols may be identical
    int rows[T+1], cols[T+1];
    rows[0] = 0;
    cols[0] = 0;
    int rows_len = 1, cols_len = 1;
    for (int i = 0; i < T; i++) {
        int want_row = 1, want_col = 1;
        int candidate_row = trees[i].row + 1;
        int candidate_col = trees[i].col + 1;
        for (int j = 0; j < rows_len; j++) {
            if (rows[j] == candidate_row) {
                want_row = 0;
            }
        }
        for (int j = 0; j < cols_len; j++) {
            if (rows[j] == candidate_col) {
                want_col = 0;
            }
        }
        if (want_row && trees[i].row != N - 1) {
            rows[rows_len] = candidate_row;
            rows_len++;
        }
        if (want_col && trees[i].col != N - 1) {
            cols[cols_len] = candidate_col;
            cols_len++;
        }
    }

    // for (int i = 0; i < rows_len; i++) {
    //     printf("%d ", rows[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < cols_len; i++) {
    //     printf("%d ", cols[i]);
    // }
    // return 0;
    // Go!
    int answer = -1;
    for (int m = N; m > 0; m--) {
        int N2 = N - m + 1;
        for (int i = 0; i < rows_len; i++) {
            if (rows[i] >= N2) {
                continue;
            }
            for (int j = 0; j < cols_len; j++) {
                if (cols[j] >= N2) {
                    continue;
                }
                // Check for trees
                int got_tree = 0;
                for (int k = 0; k < T; k++) {
                    if (rows[i] <= trees[k].row
                        && trees[k].row < rows[i] + m
                        && cols[j] <= trees[k].col
                        && trees[k].col < cols[j] + m) {
                        got_tree = 1;
                        break;
                    }
                }
                if (!got_tree) {
                    answer = m;
                    goto end;
                }
            }
        }
    }
end:
    printf("%d\n", answer);
    return 0;
}
