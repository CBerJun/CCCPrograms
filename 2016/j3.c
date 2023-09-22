/*
 * A Leetcode problem!
 * You don't have to output the substring in this problem, only the
 * length is required, which makes it simpler.
 * https://leetcode.com/problems/longest-palindromic-substring/
 */

#include <stdio.h>
#include <string.h>

#define MAX 40

char string[MAX+1];
int len = 0;

int expand(int left, int right) {
    while (left >= 0 && right < len && string[left] == string[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int main(void) {
    scanf("%s", string);
    len = strlen(string);
    int res = -1;
    for (int i = 0; i < len; i++) {
        int cur = expand(i, i);
        if (cur > res) {
            res = cur;
        }
        if (i != len-1) {
            cur = expand(i, i+1);
            if (cur > res) {
                res = cur;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
