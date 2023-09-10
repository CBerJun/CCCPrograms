#include <stdio.h>

int main() {
    int delivered, collisions;
    scanf("%d", &delivered);
    scanf("%d", &collisions);

    int score = 0;
    score += delivered * 50;
    score -= collisions * 10;
    if (delivered > collisions) {
        score += 500;
    }
    printf("%d\n", score);
}
