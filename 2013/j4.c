#include <stdio.h>
#include <stdlib.h>

#define MAX_CHORE 100

int chores[MAX_CHORE];

int cp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int t, c;
    scanf("%d", &t);
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &chores[i]);
    }
    qsort(chores, c, sizeof(int), cp);
    int i = 0;
    while (i < c && t >= 0) {
        t -= chores[i];
        if (t >= 0) {
            i++;
        }
    }
    printf("%d\n", i);
    return 0;
}
