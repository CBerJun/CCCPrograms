#include <stdio.h>
#include <string.h>

#define TEAM_NUM 4
#define GAMES (TEAM_NUM * (TEAM_NUM - 1) / 2)
#define WON 3
#define LOST 0
#define DRAW 1
#define UNKNOWN -1

int hash_game(int s1, int s2) {
    return ((TEAM_NUM - 1 + TEAM_NUM - s1) * s1 / 2) + s2 - s1 - 1;
}

/*
// I wrote this but it is not useful for this problem.
void unhash_game(int hash, int *s1, int *s2) {
    hash += 1;
    int s = 0;
    for (int i = TEAM_NUM - 1; i > 0; i--) {
        s += i;
        if (hash <= s) {
            *s1 = TEAM_NUM - 1 - i;
            *s2 = hash - (s - i) + *s1;
            break;
        }
    }
}
*/

int calculate(int record[GAMES], int t, int rec_start) {
    int ok = 0;
    int res = 0;
    for (int i = rec_start; i < GAMES; i++) {
        if (record[i] == UNKNOWN) {
            int new_rec[GAMES];
            memcpy(new_rec, record, sizeof(int[GAMES]));
            new_rec[i] = WON;
            res += calculate(new_rec, t, i + 1);
            new_rec[i] = LOST;
            res += calculate(new_rec, t, i + 1);
            new_rec[i] = DRAW;
            res += calculate(new_rec, t, i + 1);
            ok = 1;
            break;
        }
    }
    if (ok) {
        return res;
    }
    else {
        int scores[TEAM_NUM];
        memset(scores, 0, sizeof(scores));
        for (int i = 0; i < TEAM_NUM; i++) {
            for (int j = i + 1; j < TEAM_NUM; j++) {
                int i_score = record[hash_game(i, j)];
                scores[i] += i_score;
                scores[j] += i_score == WON ? LOST : \
                    (i_score == LOST ? WON : DRAW);
            }
        }
        // printf("record: [");
        // for (int i = 0; i < GAMES; i++) {
        //     printf("%d,", record[i]);
        // }
        // printf("]; scores: [");
        // for (int i = 0; i < TEAM_NUM; i++) {
        //     printf("%d,", scores[i]);
        // }
        // printf("]\n");
        for (int i = 0; i < TEAM_NUM; i++) {
            if (i != t && scores[i] >= scores[t]) {
                return 0;
            }
        }
        return 1;
    }
}

int main(void) {
    int t, g;
    scanf("%d", &t);
    scanf("%d", &g);
    int record[GAMES];
    for (int i = 0; i < GAMES; i++) {
        record[i] = UNKNOWN;
    }
    for (int i = 0; i < g; i++) {
        int s1, s2;
        int n1, n2;
        scanf("%d %d %d %d", &s1, &s2, &n1, &n2);
        record[hash_game(s1 - 1, s2 - 1)] = \
            n1 > n2 ? WON : (n1 == n2 ? DRAW : LOST);
    }
    printf("%d\n", calculate(record, t - 1, 0));
    return 0;
}
