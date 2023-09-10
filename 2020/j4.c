/*
I just learned strncpy won't add '\0' if source is longer than num...
2023.08.24
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

char T[MAX+1];
char S[MAX+1];

int main() {
    scanf("%s", T);
    scanf("%s", S);
    const size_t lens = strlen(S);
    char slice[lens+1];
    char (*cyclics)[lens+1] = malloc(sizeof(char[lens][lens+1]));
    strcpy(cyclics[0], S);
    for (int shift = 1; shift < lens; shift++) {
        // printf("strncpy(%p, %p, %d)", cyclics[shift],
        //   S + shift * sizeof(char), lens - shift);
        // printf("strncpy(%p, %p, %d)",
        //   cyclics[shift] + (lens - shift) * sizeof(char), S, shift);
        strncpy(cyclics[shift], S + shift * sizeof(char), lens - shift);
        strncpy(cyclics[shift] + (lens - shift) * sizeof(char), S, shift);
        cyclics[shift][lens] = '\0';
        // printf("shift: %s\n", cyclics[shift]);
    }
    for (int i = 0; i <= strlen(T) - lens; i++) {
        strncpy(slice, T + i * sizeof(char), lens);
        slice[lens] = '\0';
        // printf("slice: %s\n", slice);
        for (int shift = 0; shift < lens; shift++) {
            if (strcmp(slice, cyclics[shift]) == 0) {
                printf("yes\n");
                goto end;
            }
        }
    }
    printf("no\n");
end:
    free(cyclics);
    return 0;
}
