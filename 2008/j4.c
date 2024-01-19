#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char ch;
    bool first;
    char ops[20];
    int sp = 0;
    while (1) {
        first = true;
        while (1) {
            ch = getchar();
            if (first && ch == '0') {
                goto exit;
            }
            first = false;
            if (ch == '+') {
                ops[sp++] = 0;
            }
            else if (ch == '-') {
                ops[sp++] = 1;
            }
            else {
                printf("%c ", ch);
                while (sp > 0 && (ops[sp - 1] & 2)) {
                    putchar((ops[--sp] & 1) ? '-' : '+');
                    if (sp == 0) {
                        getchar();  // '\n'
                        putchar('\n');
                        goto cont;
                    }
                    else {
                        putchar(' ');
                    }
                }
                ops[sp - 1] |= 2;
            }
            getchar();  // ' '
        }
cont:
        ;
    }
exit:
    return 0;
}
