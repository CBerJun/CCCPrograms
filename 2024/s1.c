#include <stdio.h>

int h[500000];

int main(void) {
    int n;
    scanf("%d", &n);
    const int hn = n / 2;
    for (int i = 0; i < hn; ++i) {
        scanf("%d", &h[i]);
    }
    int res = 0;
    for (int i = 0; i < hn; ++i) {
        int t;
        scanf("%d", &t);
        res += (t == h[i]);
    }
    printf("%d\n", res * 2);
    return 0;
}
