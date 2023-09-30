#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 30

char s[MAX+1];
char res[3*MAX+1];
// Vowels must be sorted
const char VOWELS[] = {'a', 'e', 'i', 'o', 'u'};
const int VOWEL_COUNT = sizeof(VOWELS) / sizeof(VOWELS[0]);

int main(void) {
    int idx = 0;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        res[idx++] = s[i];
        int min_diff = 100;
        int min_diff_i;
        int got_vowel = 0;
        for (int j = 0; j < VOWEL_COUNT; j++) {
            int diff = abs(s[i] - VOWELS[j]);
            if (diff < min_diff) {
                  // Must be strictly < here
                min_diff = diff;
                min_diff_i = j;
            }
        }
        if (min_diff == 0) {
            continue;
        }
        res[idx++] = VOWELS[min_diff_i];
        if (s[i] == 'z') {
            res[idx++] = 'z';
        }
        else {
            int need_2 = 0;
            // Based on fact that no vowel letters are consecutive
            for (int j = 0; j < VOWEL_COUNT; j++) {
                if (s[i] + 1 == VOWELS[j]) {
                    need_2 = 1;
                    break;
                }
            }
            res[idx++] = s[i] + (need_2 ? 2 : 1);
        }
    }
    printf("%s\n", res);
    return 0;
}
