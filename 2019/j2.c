#include <stdio.h>

int main(void) {
    int L;
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        int t;
        scanf("%d", &t);
        getchar();  // space
        char ch = getchar();
        getchar();  // new line
        for (int j = 0; j < t; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
