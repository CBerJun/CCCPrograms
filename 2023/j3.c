#include <stdio.h>

int main() {
    int people_no;
    int weight[5] = {0, 0, 0, 0, 0};
    scanf("%d", &people_no);
    for (int i = 0; i < people_no; i++) {
        char availability[6];
        scanf("%s", availability);
        for (int j = 0; j < 5; j++) {
            if (availability[j] == 'Y') {
                weight[j]++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 5; i++) {
        if (weight[i] > max) {
            max = weight[i];
        }
    }
    int is_first = 1;
    for (int i = 0; i < 5; i++) {
        if (weight[i] == max) {
            if (is_first) {
                is_first = 0;
                printf("%d", i + 1);
            }
            else {
                printf(",%d", i + 1);
            }
        }
    }
    printf("\n");
    return 0;
}
