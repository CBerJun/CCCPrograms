#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Digit 11?\n");
    scanf("%d", &a);
    printf("Digit 12?\n");
    scanf("%d", &b);
    printf("Digit 13?\n");
    scanf("%d", &c);
    printf("The 1-3-sum is %d\n", 91 + a + c + 3 * b);
    return 0;
}
