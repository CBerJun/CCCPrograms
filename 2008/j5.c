#include <stdio.h>
#include <stdbool.h>

const int rules[][4] = {
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 2, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1}
};
const int num_rules = sizeof(rules) / sizeof(rules[0]);

bool can_win(int a, int b, int c, int d) {
    for (int i = 0; i < num_rules; ++i) {
        if (a >= rules[i][0]
            && b >= rules[i][1]
            && c >= rules[i][2]
            && d >= rules[i][3]
            && !can_win(
                a - rules[i][0], b - rules[i][1],
                c - rules[i][2], d - rules[i][3]
            )
        ) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int a, b, c, d;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%s\n", can_win(a, b, c, d) ? "Patrick" : "Roland");
    }
    return 0;
}
