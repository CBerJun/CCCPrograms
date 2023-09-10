/* 00:52:11, 14/15 scores
   1 score lost because C does not have HASHMAP...
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 12

char n1[MAX_NAME], n2[MAX_NAME], n3[MAX_NAME];

int is_in(char n[MAX_NAME]) {
    return !(strcmp(n1, n) && strcmp(n2, n) && strcmp(n3, n));
}

int main() {
    int c1, c2;
    int g;
    scanf("%d", &c1);
    char (*c1_names)[MAX_NAME] = malloc(sizeof(char[c1 * 2][MAX_NAME]));
    // char c1_names[c1 * 2][MAX_NAME];
    int *c1_ok = malloc(sizeof(int[c1]));
    // int c1_ok[c1];
    for (int i = 0; i < c1; i++) {
        c1_ok[i] = 0;
        scanf("%s", c1_names[2 * i]);
        scanf("%s", c1_names[2 * i + 1]);
    }
    scanf("%d", &c2);
    char (*c2_names)[MAX_NAME] = malloc(sizeof(char[c2 * 2][MAX_NAME]));
    // char c2_names[c2 * 2][MAX_NAME];
    int *c2_not_ok = malloc(sizeof(int[c2]));
    // int c2_not_ok[c2];
    for (int i = 0; i < c2; i++) {
        c2_not_ok[i] = 0;
        scanf("%s", c2_names[2 * i]);
        scanf("%s", c2_names[2 * i + 1]);
    }
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        scanf("%s", n1);
        scanf("%s", n2);
        scanf("%s", n3);
        for (int i = 0; i < c1; i++) {
            if (is_in(c1_names[i*2]) && is_in(c1_names[i*2+1])) {
                c1_ok[i] = 1;
            }
        }
        for (int i = 0; i < c2; i++) {
            if (is_in(c2_names[i*2]) && is_in(c2_names[i*2+1])) {
                c2_not_ok[i] = 1;
            }
        }
    }
    int violates = c1;
    for (int i = 0; i < c1; i++) {
        if (c1_ok[i] == 1) {
            violates--;
        }
    }
    for (int i = 0; i < c2; i++) {
        if (c2_not_ok[i] == 1) {
            violates++;
        }
    }
    printf("%d\n", violates);
    free(c2_names);
    free(c2_not_ok);
    free(c1_names);
    free(c1_ok);
    return 0;
}
