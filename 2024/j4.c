#include <stdio.h>
#include <stdbool.h>

char inp[500001];
char act[500001];
int cnt1[26];
int cnt2[26];
int n1, n2;

bool mycmp(char silent, char wrong_from, char wrong_to) {
    int j = 0;
    for (int i = 0; i < n1; ++i) {
        if (inp[i] == silent)
            continue;
        if (inp[i] == wrong_from) {
            if (wrong_to != act[j++]) {
                return false;
            }
        }
        else {
            if (inp[i] != act[j++]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    scanf("%s%n ", inp, &n1);
    scanf("%s%n", act, &n2);
    for (int i = 0; i < n1; ++i) {
        ++cnt1[inp[i] - 'a'];
    }
    for (int i = 0; i < n2; ++i) {
        ++cnt2[act[i] - 'a'];
    }
    int inp_c1 = -1, inp_c2 = -1;
    int act_c = -1;
    for (int i = 0; i < 26; ++i) {
        if (cnt1[i] == cnt2[i])
            continue;
        if (cnt1[i]) {
            if (inp_c1 != -1)
                inp_c2 = i;
            else
                inp_c1 = i;
        }
        else {
            act_c = i;
        }
    }
    if (inp_c2 == -1) {
        printf("%c %c\n-\n", inp_c1 + 'a', act_c + 'a');
    }
    else {
        bool c1_silent;
        if (cnt1[inp_c1] != cnt1[inp_c2]) {
            c1_silent = (cnt1[inp_c1] != cnt2[act_c]);
        }
        else {
            c1_silent = mycmp('a' + inp_c1, 'a' + inp_c2, 'a' + act_c);
        }
        if (c1_silent) {
            printf("%c %c\n%c\n", inp_c2 + 'a', act_c + 'a', inp_c1 + 'a');
        }
        else {
            printf("%c %c\n%c\n", inp_c1 + 'a', act_c + 'a', inp_c2 + 'a');
        }
    }
    return 0;
}
