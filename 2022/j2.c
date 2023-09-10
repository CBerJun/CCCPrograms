/* 00:07:08 */

#include <stdio.h>

int main() {
    int is_gold = 1;
    int players, player40 = 0;
    int score, foul;
    scanf("%d", &players);
    for (int i = 0; i < players; i++) {
        scanf("%d", &score);
        scanf("%d", &foul);
        if (score * 5 - foul * 3 > 40) {
            player40++;
        }
        else {
            is_gold = 0;
        }
    }
    printf("%d%s\n", player40, is_gold ? "+" : "");
    return 0;
}
