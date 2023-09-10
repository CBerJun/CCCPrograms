/* 00:02:28 */

#include <stdio.h>

int main() {
    int reg, small;
    scanf("%d", &reg);
    scanf("%d", &small);
    printf("%d\n", reg * 8 + small * 3 - 28);
    return 0;
}
