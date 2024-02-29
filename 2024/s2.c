/*
 * A one pass solution I wrote during the contest...
 * But actually a simple two-pass algorithm is enough to pass.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int memo[26];
int tp[26];  // 0 -> not read, 1 -> heavy, -1 -> ..,

int main(void) {
    int t, n;
    scanf("%d %d ", &t, &n);
    for (int i = 0; i < t; ++i) {
        memset(memo, 0, sizeof(int) * 26);
        memset(tp, 0, sizeof(int) * 26);
        int state = -1;  // -1 -> unsure; 0 -> heavy first; 1 -> ..
        bool oddj = false;
        for (int j = 0; j < n; ++j) {
            char c = getchar() - 'a';
            ++memo[c];
            if (state == -1) {
                if (memo[c] > 1) {
                    state = oddj;
                    if (state) {
                        for (int k = 0; k < 26; ++k) {
                            tp[k] = -tp[k];
                        }
                    }
                }
                else {
                    tp[c] = oddj ? -1 : 1;
                }
            }
            if (state == oddj) {
                // heavy
                if (tp[c] == -1) goto F;
                tp[c] = 1;
            }
            else if (state != -1) {
                // light
                if (tp[c] == 1) goto F;
                tp[c] = -1;
                if (memo[c] != 1) goto F;
            }
            oddj = !oddj;
        }
        // make sure heavy letters appear >1 times
        for (int k = 0; k < 26; ++k) {
            if (tp[k] == 1 && memo[k] == 1) {
                goto F;
            }
        }
        putchar('T');
        goto ED;
F:
        putchar('F');
ED:
        putchar('\n');
        scanf("%*[^\n]");
        getchar();  // \n
    }
    return 0;
}
