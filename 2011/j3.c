/**
 * If t(m-1) < t(m)
 * then 2t(m-1) < t(m-2)   i.e. t(m-2) > 2t(m-1)
 * then 2t(m-3) < 3t(m-2)
 * then 5t(m-3) < 3t(m-4)  i.e. 3t(m-4) > 5t(m-3)
 * then 5t(m-5) < 8t(m-4)
 * ...
 * Note: the while condition expands to:
 *   (i % 2 == 0 && a * t1 >= b * t2)
 *   || (i % 2 == 1 && a * t1 <= b * t2)
 */

#include <stdio.h>

int main(void) {
    int t1, t2;
    scanf("%d", &t1);
    scanf("%d", &t2);
    int a = 1, b = 1, i = 2;
    while ((a * t1 > b * t2) ^ (i % 2)) {
        int sum = a + b;
        a = b;
        b = sum;
        i++;
    }
    printf("%d\n", i);
    return 0;
}
