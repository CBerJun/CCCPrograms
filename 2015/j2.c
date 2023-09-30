/* I was having a hard time with scanf... */

#include <stdio.h>
#include <string.h>

#define MAX 255

char s[MAX+1];

int main(void) {
    int smile = 0, frown = 0;
    fgets(s, MAX, stdin);
    for (int i = 0; i < strlen(s) - 2; i++) {
        if ((s[i] == ':') && (s[i+1] == '-')) {
            if (s[i+2] == ')') {
                smile++;
            }
            else if (s[i+2] == '(') {
                frown++;
            }
        }
    }
    if ((smile == 0) && (frown == 0)) {
        printf("none\n");
    }
    else if (smile > frown) {
        printf("happy\n");
    }
    else if (frown > smile) {
        printf("sad\n");
    }
    else {
        printf("unsure\n");
    }
    return 0;
}
