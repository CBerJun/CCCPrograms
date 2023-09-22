#include <stdio.h>

// in (minutes)
#define UNIT 10
// in (UNIT/2 minutes)
#define REGULAR_TIME 24

int main(void) {
    int hour, min;
    int rest = REGULAR_TIME;
    scanf("%d", &hour);
    getchar();  // ':'
    scanf("%d", &min);
    // assert min % (UNIT * 2) == 0;
    while (rest > 0) {
        // Decrement rest
        int totalmin = hour * 60 + min;
        if ((420 <= totalmin && totalmin < 600)
                || (900 <= totalmin && totalmin < 1140)) {
            rest--;
            // printf("dec by 1: %d:%d; %d\n", hour, min, rest);
        }
        else {
            rest -= 2;
            // printf("dec by 2: %d:%d; %d\n", hour, min, rest);
        }
        // Decrement time
        min += UNIT;
        if (min >= 60) {
            min -= 60;
            hour++;
        }
        if (hour >= 24) {
            hour -= 24;
        }
    }
    printf("%02d:%02d\n", hour, min);
    return 0;
}
