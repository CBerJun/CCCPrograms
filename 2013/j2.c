#include <stdio.h>
#include <string.h>

#define MAX 30

char s[MAX+1];

int main(void) {
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        if (
            s[i] != 'I' && s[i] != 'O' && s[i] != 'S' && s[i] != 'H'
            && s[i] != 'Z' && s[i] != 'X' && s[i] != 'N' 
        ) {
            goto no;
        }
    }
    printf("YES\n");
    goto exit;
no:
    printf("NO\n");
exit:
    return 0;
}
