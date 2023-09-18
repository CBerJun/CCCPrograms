#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    int fuel;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d", &fuel);
    int fuel_required = abs(x1 - x2) + abs(y1 - y2);
    int fuel_delta = fuel - fuel_required;
    if (fuel_delta >= 0 && fuel_delta % 2 == 0) {
        printf("Y");
    }
    else {
        printf("N");
    }
    printf("\n");
    return 0;
}
