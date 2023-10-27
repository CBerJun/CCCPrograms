#include <stdio.h>

#define L 4

int main(void) {
    int prev = -1;
    int trend = -2;
    for (int i = 0; i < L; i++) {
        int v;
        scanf("%d", &v);
        if (prev != -1) {
            int cur_trend = prev > v ? -1 : (prev < v ? 1 : 0);
            if (trend == -2) {
                trend = cur_trend;
            }
            else {
                if (trend != cur_trend) {
                    goto no;
                }
            }
        }
        prev = v;
    }
    if (trend == 0) {
        printf("Fish At Constant Depth");
    }
    else if (trend == -1) {
        printf("Fish Diving");
    }
    else {
        printf("Fish Rising");
    }
    goto exit;
no:
    printf("No Fish");
exit:
    printf("\n");
    return 0;
}
