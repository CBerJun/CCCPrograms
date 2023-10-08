#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (a + b + c == 180) {
        if (a == b && b == c && c == 60) {
            printf("Equilateral");
        }
        else if (a == b || b == c || c == a) {
            printf("Isosceles");
        }
        else {
            printf("Scalene");
        }
    }
    else {
        printf("Error");
    }
    printf("\n");
    return 0;
}
