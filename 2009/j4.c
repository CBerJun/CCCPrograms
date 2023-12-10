/* I like this problem. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char words[][8] = {
    "WELCOME",
    "TO",
    "CCC",
    "GOOD",
    "LUCK",
    "TODAY"
};
const size_t n_words = sizeof(words) / sizeof(words[0]);
const char space = '.';

int main(void) {
    int w;
    // This is required in problem description but in test cases this
    // prompt is not shown:
    // printf("Enter w: ");
    scanf("%d", &w);
    int i = 0;
    while (i < n_words) {
        int cap = w;
        int l;
        const int begin = i;
        while (i < n_words && cap >= (l = strlen(words[i]))) {
            cap -= l + 1;
            // +1: one base space for each word ...
            ++i;
        }
        cap += 1;  // ... except the last word
        // the line contains words[begin] to words[i - 1]
        // cap is # of extra spaces to be inserted now
        const int cnt = i - begin;
        // printf("(cnt: %d, cap: %d, begin: %d)", cnt, cap, begin);
        if (cnt == 1) {
            printf("%s", words[begin]);
            for (int j = 0; j < cap; ++j) {
                putchar(space);
            }
        }
        else {
            // -1: the last word does not want trailing spaces
            div_t cap_d = div(cap, cnt - 1);
            for (int j = 0; j < cnt; ++j) {
                printf("%s", words[begin + j]);
                if (j != cnt - 1) {
                    putchar(space);
                    for (int k = 0; k < cap_d.quot; ++k) {
                        putchar(space);
                    }
                    if (cap_d.rem > 0) {
                        putchar(space);
                        cap_d.rem--;
                    }
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
