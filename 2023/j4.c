#include <stdio.h>

int main() {
    int columns;
    scanf("%d", &columns);
    getchar();  // '\n'
    char row1[columns], row2[columns];
    for (int j = 0; j < columns; j++) {
        row1[j] = getchar();
        getchar();  // space or '\n'
    }
    for (int j = 0; j < columns; j++) {
        row2[j] = getchar();
        getchar();  // space or '\n'
    }
    int sum = 0;
    for (int i = 0; i < columns; i++) {
        if (row1[i] == '1') {
            sum += 3;
        }
        if (row2[i] == '1') {
            sum += 3;
        }
    }
    for (int i = 0; i < columns - 1; i++) {
        if (row1[i] == '1' && row1[i + 1] == '1') {
            sum -= 2;
        }
        if (row2[i] == '1' && row2[i + 1] == '1') {
            sum -= 2;
        }
        if (i % 2 == 0 && row1[i] == '1' && row2[i] == '1') {
            sum -= 2;
        }
    }
    if (columns % 2 == 1
        && row1[columns - 1] == '1' && row2[columns - 1] == '1') {
        sum -= 2;
    }
    printf("%d\n", sum);
    return 0;
}
