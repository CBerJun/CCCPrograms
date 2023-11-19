/* I like this problem :) */

#include <stdio.h>

int rax = 0, rbx = 0;

int* reg(char reg) {
    return (reg == 'A') ? &rax : &rbx;
}

int main(void) {
    int insn;
    while (1) {
        scanf("%d", &insn);
        if (insn == 7) {
            break;
        }
        getchar();  // whitespace
        int *op1 = NULL, *op2 = NULL;
        op1 = reg(getchar());
        if (insn == 1) {
            int n;
            scanf("%d", &n);
            *op1 = n;
        }
        else if (insn == 2) {
            printf("%d\n", *op1);
        }
        else {
            getchar();  // whitespace
            op2 = reg(getchar());
            switch (insn) {
                case 3:
                    *op1 += *op2;
                    break;
                case 4:
                    *op1 *= *op2;
                    break;
                case 5:
                    *op1 -= *op2;
                    break;
                case 6:
                    *op1 /= *op2;
                    break;
            }
        }
    }
    return 0;
}
