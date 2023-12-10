#include <stdio.h>
#include <stdlib.h>

int mod(int a, int b) {
    return (a % b + b) % b;
}

int main(void) {
    int a;
    scanf("%d", &a);
    div_t sj = div(a, 100);
    sj.quot += 1;
    sj.rem += 30;
    if (sj.rem >= 60) {
        sj.quot++;
        sj.rem -= 60;
    }
    const int sj_i = mod(100 * sj.quot + sj.rem, 2400);
    printf(
        "%d in Ottawa.\n"
        "%d in Victoria.\n"
        "%d in Edmonton.\n"
        "%d in Winnipeg.\n"
        "%d in Toronto.\n"
        "%d in Halifax.\n"
        "%d in St. John's.\n",
        a,
        mod(a - 300, 2400),
        mod(a - 200, 2400),
        mod(a - 100, 2400),
        a,
        mod(a + 100, 2400),
        sj_i
    );
    return 0;
}
