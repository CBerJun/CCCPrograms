#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_NAME 15

int main() {
    int P;
    scanf("%d", &P);
    char winner[MAX_NAME];
    char name[MAX_NAME];
    int win_bid = 0, bid;
    for (int i = 0; i < P; i++) {
        scanf("%s", name);
        scanf("%d", &bid);
        if (bid > win_bid) {
            win_bid = bid;
            strcpy(winner, name);
        }
    }
    printf("%s\n", winner);
    return 0;
}
