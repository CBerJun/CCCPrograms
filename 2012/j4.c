/* C's % operator xD */

#include <stdio.h>

int mod(int a, int b) {
    int rem = a % b;
    return rem < 0 ? rem + b : rem;
}

char decodechar(char c, int s) {
    return (char) (mod(c - 'A' - s, 26) + 'A');
}

int main(void) {
    int k;
    int i = 1;
    char ch;
    scanf("%d", &k);
    getchar();  // '\n'
    while ((ch = getchar()) != '\n') {
        putchar(decodechar(ch, k + 3 * i));
        i++;
    }
    putchar('\n');
    return 0;
}
