#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// horizontal, vertical, diagonal
#define H_RIGHT 0
#define H_LEFT 1
#define V_DOWN 2
#define V_UP 3
#define D_LEFTDOWN 4
#define D_RIGHTDOWN 5
#define D_LEFTUP 6
#define D_RIGHTUP 7

const int ENTRY_DIRS[] = {
    H_RIGHT, V_DOWN, D_LEFTDOWN, D_RIGHTDOWN,
    H_LEFT, V_UP, D_LEFTUP, D_RIGHTUP
};

struct I2d {
    int row;
    int column;
};

int find_no_fold(int row, int column, char table[row][column],
                 int i, int j, int direction, char target[], int target_len) {
    /* Return 0 if found target at i, j with direction.
       No folding or reverse considered. */
    // printf("Finding: %d %d dir: %d for %s\n", i, j, direction, target);
    struct I2d i2ds[target_len];
    switch (direction) {
        case H_RIGHT:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i; i2ds[k].column = j + k;
            }
            break;
        case H_LEFT:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i; i2ds[k].column = j - k;
            }
            break;
        case V_DOWN:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i + k; i2ds[k].column = j;
            }
            break;
        case V_UP:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i - k; i2ds[k].column = j;
            }
            break;
        case D_LEFTDOWN:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i + k; i2ds[k].column = j - k;
            }
            break;
        case D_RIGHTDOWN:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i + k; i2ds[k].column = j + k;
            }
            break;
        case D_LEFTUP:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i - k; i2ds[k].column = j - k;
            }
            break;
        case D_RIGHTUP:
            for (int k = 0; k < target_len; k++) {
                i2ds[k].row = i - k; i2ds[k].column = j + k;
            }
            break;
    }
    for (int k = 0; k < target_len; k++) {
        struct I2d i2d = i2ds[k];
        // printf("%d: %d %d\n", k, i2d.row, i2d.column);
        if (i2d.row < 0 || i2d.row >= row
            || i2d.column < 0 || i2d.column >= column) {
            return -1;
        }
        if (table[i2d.row][i2d.column] != target[k]) {
            return -1;
        }
    }
    return 0;
}

int search(int row, int column, char table[row][column], char target[]) {
    /* Search for target. Return times found. */
    int result = 0;
    size_t target_len = strlen(target);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            for (int k = 2; k < target_len + 1; k++) {
                // If target = "ABCDE", k = 2
                // first_target = "AB", second_target = "CDE"
                int first_len = k;
                char first_target[first_len + 1];
                memset(first_target, 0, first_len + 1);
                strncpy(first_target, target, first_len);
                int second_len = target_len - k;
                char second_target[second_len + 1];
                memset(second_target, 0, second_len + 1);
                strncpy(second_target, target + k * sizeof(char),
                        second_len);
                // printf("Targets: %s %d %s %s\n", target, k,
                //        first_target, second_target);
                for (int l = 0; l < sizeof(ENTRY_DIRS) / sizeof(int); l++) {
                    int dir = ENTRY_DIRS[l];
                    if (find_no_fold(row, column, table, i, j,
                                     dir, first_target, first_len) == 0) {
                        int dir_r1, dir_r2;
                        int i_r1 = i, j_r1 = j, i_r2 = i, j_r2 = j;
                        switch (dir) {
                            case H_LEFT:
                            case H_RIGHT:
                                dir_r1 = V_DOWN; dir_r2 = V_UP;
                                i_r1 += 1; i_r2 -= 1;
                                break;
                            case V_DOWN:
                            case V_UP:
                                dir_r1 = H_RIGHT; dir_r2 = H_LEFT;
                                j_r1 += 1; j_r2 -= 1;
                                break;
                            case D_LEFTDOWN:
                            case D_RIGHTUP:
                                dir_r1 = D_LEFTUP; dir_r2 = D_RIGHTDOWN;
                                i_r1 -= 1; j_r1 -= 1;
                                i_r2 += 1; j_r2 += 1;
                                break;
                            case D_RIGHTDOWN:
                            case D_LEFTUP:
                                dir_r1 = D_RIGHTUP; dir_r2 = D_LEFTDOWN;
                                i_r1 -= 1; j_r1 += 1;
                                i_r2 += 1; j_r2 -= 1;
                                break;
                        }
                        switch (dir) {
                            case H_LEFT:
                                j_r1 -= k - 1; j_r2 -= k - 1; break;
                            case H_RIGHT:
                                j_r1 += k - 1; j_r2 += k - 1; break;
                            case V_DOWN:
                                i_r1 += k - 1; i_r2 += k - 1; break;
                            case V_UP:
                                i_r1 -= k - 1; i_r2 -= k - 1; break;
                            case D_LEFTDOWN:
                                i_r1 += k - 1; j_r1 -= k - 1;
                                i_r2 += k - 1; j_r2 -= k - 1; break;
                            case D_RIGHTDOWN:
                                i_r1 += k - 1; j_r1 += k - 1;
                                i_r2 += k - 1; j_r2 += k - 1; break;
                            case D_LEFTUP:
                                i_r1 -= k - 1; j_r1 -= k - 1;
                                i_r2 -= k - 1; j_r2 -= k - 1; break;
                            case D_RIGHTUP:
                                i_r1 -= k - 1; j_r1 += k - 1;
                                i_r2 -= k - 1; j_r2 += k - 1; break;
                        }
                        if (second_len == 0) {
                            // printf("Found: %d %d dir %d\n", i, j, dir);
                            result++;
                            continue;
                        }
                        if (find_no_fold(row, column, table, i_r1, j_r1, dir_r1,
                                         second_target, second_len) == 0) {
                            // printf("Found: %d %d dir %d + %d %d dir %d\n",
                            //        i, j, dir, i_r1, j_r1, dir_r1);
                            result++;
                        }
                        if (find_no_fold(row, column, table, i_r2, j_r2, dir_r2,
                                         second_target, second_len) == 0) {
                            // printf("Found: %d %d dir %d + %d %d dir %d\n",
                            //        i, j, dir, i_r2, j_r2, dir_r2);
                            result++;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    char target[MAX];
    int row, column;
    scanf("%s", target);
    scanf("%d", &row);
    scanf("%d", &column);
    getchar();  // '\n'
    char table[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%c", &table[i][j]);
            getchar();  // space or '\n'
        }
    }
    int result = search(row, column, table, target);
    printf("%d\n", result);
    return 0;
}

int test() {
    char table[5][5] = {
        "ABCAB",
        "BACAB",
        "CBAAB",
        "ABACB",
        "ACBAB"
    };
    int r = search(5, 5, table, "ACABC");
    // int r = find_no_fold(5, 5, table, 1, 4, V_DOWN, "BC", 2);
    printf("%d\n", r);
    return 0;
}
