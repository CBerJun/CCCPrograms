#include <stdio.h>

int main(void) {
    float w, h;
    scanf("%f %f", &w, &h);
    const float bmi = w / (h * h);
    if (bmi < 18.5) {
        printf("Underweight");
    }
    else if (bmi <= 25) {
        printf("Normal weight");
    }
    else {
        printf("Overweight");
    }
    printf("\n");
    return 0;
}
