#include <stdio.h>

int main(void) {
    int x, l;
    printf("Enter the speed limit: ");
    scanf("%d", &l);
    printf("Enter the recorded speed of the car: ");
    scanf("%d", &x);
    if (x <= l) {
        printf("Congratulations, you are within the speed limit");
    }
    else if (x - l <= 20) {
        printf("You are speeding and your fine is $ 100");
    }
    else if (x - l <= 30) {
        printf("You are speeding and your fine is $ 270");
    }
    else {
        printf("You are speeding and your fine is $ 500");
    }
    printf("\n");
    return 0;
}
