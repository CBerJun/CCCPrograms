#include <stdio.h>

int main(void) {
    int L;
    scanf("%d", &L);
    getchar();  // new line
    for (int i = 0; i < L; i++) {
        char cur = getchar();
        char last = '\n';  // valid char will never be '\n'
        int c = -1;
        while (cur != '\n') {
            if (cur == last) {
                c++;
            }
            else {
                if (c != -1) {
                    printf("%d %c ", c, last);
                }
                c = 1;
            }
            last = cur;
            cur = getchar();
        }
        // At least 1 char, so c must != -1
        printf("%d %c", c, last);
        printf("\n");
    }
    return 0;
}
