#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int mul;
    if (k == 0) mul = 1;
    else if (k == 1) mul = 11;
    else if (k == 2) mul = 111;
    else if (k == 3) mul = 1111;
    else if (k == 4) mul = 11111;
    else if (k == 5) mul = 111111;
    printf("%d\n", n * mul);
    return 0;
}
