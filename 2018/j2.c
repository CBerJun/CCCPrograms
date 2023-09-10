#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    char d1[N+1], d2[N+1];
    scanf("%s", d1);
    scanf("%s", d2);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (d1[i] == 'C' && d2[i] == 'C') {
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
