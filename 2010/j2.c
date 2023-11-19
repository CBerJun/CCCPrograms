#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b, c, d, s;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &s);
    div_t N = div(s, a + b), B = div(s, c + d);
    int NS = N.quot * (a - b), BS = B.quot * (c - d);
    if (N.rem > a) {
        NS += 2 * a - N.rem;
    }
    else {
        NS += N.rem;
    }
    if (B.rem > c) {
        BS += 2 * c - B.rem;
    }
    else {
        BS += B.rem;
    }
    if (NS < BS) {
        printf("Byron\n");
    }
    else if (NS > BS) {
        printf("Nikky\n");
    }
    else {
        printf("Tied\n");
    }
    return 0;
}
