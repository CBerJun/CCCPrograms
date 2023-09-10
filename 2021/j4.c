/* 13/15 (probably) since TLE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l = 0, m = 0;  // boundaries

char get_expected(int i) {
    char expected;
    if (i < l) {
        expected = 'L';
    }
    else if (i < m) {
        expected = 'M';
    }
    else {
        expected = 'S';
    }
    return expected;
}

int main() {
    char *s = malloc(500001 * sizeof(char));
    int swaps = 0;
    scanf("%s", s);
    const int LEN = strlen(s);
    for (int i = 0; i < LEN; i++) {
        switch (s[i]) {
            case 'L':
                l++;
            case 'M':
                m++;
        }
    }
    for (int i = 0; i < LEN; i++) {
        char i_expected = get_expected(i);
        // printf("char %d, exp %c\n", i, i_expected);
        if (s[i] != i_expected) {
            int j = LEN - 1;
            int backup_j;
            int j_expected;
            while (s[j] != i_expected
                   || s[i] != (j_expected = get_expected(j))) {
                if (j <= i) {
                    // printf("Use backup: ");
                    j = backup_j;
                    break;
                }
                // printf("i, j: %d, %d\n", i, j);
                if (s[j] == i_expected && s[j] != j_expected) {
                    backup_j = j;
                }
                j--;
            }
            // printf("swap %d %d\n", i, j);
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            swaps++;
        }
    }
    printf("%d\n", swaps);
    // s[1001] = '\0';
    // printf("S: %s", s);
    return 0;
}


/*
// This get 9/15 scores -- best solution given when M does not present,
// works but may not produce best solution (which is required) when
// M presents.

int swaps = 0;

int sort(char *s, int i, int j, char lsymbol, char rsymbol) {
    while (i < j) {
        if (s[i] == rsymbol) {
            while (s[j] != lsymbol) {
                if (i >= j) {
                    goto end;
                }
                j--;
            }
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            swaps++;
            j--;  // this lsymbol has been consumed...
        }
        if (i < j) {
            // Make sure i is accurate since we return it as mid point
            i++;
        }
    }
end:
    return i;  // mid point; either i or j
}

int main() {
    char *s = malloc(500001 * sizeof(char));
    scanf("%s", s);
    const int END = strlen(s) - 1;
    int mid = sort(s, 0, END, 'L', 'S');
    // mid should be edge of L and S
    // index <= mid will be M and L, >= mid will be S and M.
    sort(s, 0, mid, 'L', 'M');
    sort(s, mid, END, 'M', 'S');
    printf("%d\n", swaps);
    return 0;
}
*/
