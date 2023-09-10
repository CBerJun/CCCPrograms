#include <stdio.h>
#include <math.h>

int main() {
    int P, N, R;
    scanf("%d", &P);
    scanf("%d", &N);
    scanf("%d", &R);
    int cur = 0;
    int day = 0;
    while (cur <= P) {
        cur += N * pow(R, day);
        day++;
    }
    printf("%d", day-1);
    return 0;
}
