#include <stdio.h>
#include <math.h>

#define S 5

int main(void) {
    int last = 0;
    int pos[S];
    for (int i = 1; i < S; i++) {
        scanf("%d", &pos[i]);
        pos[i] += last;
        last = pos[i];
    }
    pos[0] = 0;
    // for (int i = 0; i < S; i++) {
    //     printf("%d ", pos[i]);
    // }
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            printf("%d ", abs(pos[i] - pos[j]));
        }
        printf("\n");
    }
    return 0;
}
