#include <stdio.h>
#include <stdbool.h>

#define WIDTH 200
#define DEPTH 200
#define CELLAT(x, y) (map[(x) + WIDTH][-(y) - 1])

bool map[2*WIDTH+1][DEPTH];
const char pre_insns[] = {'d', 'r', 'd', 'r', 'u', 'r', 'd', 'l', 'u'};
const int pre_values[] = {2, 3, 2, 2, 2, 2, 4, 8, 2};
int x = 0, y = -1;

bool move(char insn, int v) {
    bool res = false;
    switch (insn) {
        case 'u':
            for (int i = 1; i <= v; i++) {
                if (CELLAT(x, y + i)) {
                    res = true;
                }
                CELLAT(x, y + i) = true;
            }
            y += v;
            break;
        case 'd':
            for (int i = 1; i <= v; i++) {
                if (CELLAT(x, y - i)) {
                    res = true;
                }
                CELLAT(x, y - i) = true;
            }
            y -= v;
            break;
        case 'l':
            for (int i = 1; i <= v; i++) {
                if (CELLAT(x - i, y)) {
                    res = true;
                }
                CELLAT(x - i, y) = true;
            }
            x -= v;
            break;
        case 'r':
            for (int i = 1; i <= v; i++) {
                if (CELLAT(x + i, y)) {
                    res = true;
                }
                CELLAT(x + i, y) = true;
            }
            x += v;
            break;
    }
    return res;
}

int main(void) {
    for (int i = 0; i < sizeof(pre_insns); i++) {
        move(pre_insns[i], pre_values[i]);
    }
    while (true) {
        char insn;
        int v;
        scanf(" %c %d", &insn, &v);
        if (insn == 'q') {
            break;
        }
        bool break_ = move(insn, v);
        printf("%d %d ", x, y);
        if (break_) {
            printf("DANGER\n");
            break;
        }
        printf("safe\n");
    }
    return 0;
}
