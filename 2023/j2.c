#include <stdio.h>
#include <string.h>

#define CHILI_COUNT 6

const char *CHILIS[CHILI_COUNT] = {
    "Poblano", "Mirasol", "Serrano", "Cayenne", "Thai", "Habanero"
};
const int CHILI_SHU[] = {
    1500, 6000, 15500, 40000, 75000, 125000
};

int main() {
    int chili_count, shu_sum = 0;
    char chili_name[30];
    scanf("%d", &chili_count);
    for (int i = 0; i < chili_count; i++) {
        scanf("%s", chili_name);
        for (int j = 0; j < CHILI_COUNT; j++) {
            if (strcmp(chili_name, CHILIS[j]) == 0) {
                shu_sum += CHILI_SHU[j];
            }
        }
    }
    printf("%d\n", shu_sum);
    return 0;
}
