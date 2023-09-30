#include <stdio.h>

#define MAX_X 100

// Index 0 not used:
int total[MAX_X+1];
int recv[MAX_X+1];

int main(void) {
    int M;
    int time = 0;
    int no_interval_1 = 1;
    scanf("%d", &M);
    for (int i = 1; i < MAX_X + 1; i++) {
        total[i] = 0;
        recv[i] = -1;
    }
    for (int i = 0; i < M; i++) {
        char op;
        int v;
        getchar();  // '\n'
        op = getchar();
        scanf("%d", &v);
        // Time
        if (op == 'W') {
            time += v;
            no_interval_1 = 1;
        }
        else if (!no_interval_1) {
            time++;
        }
        else {
            no_interval_1 = 0;
        }
        // Message
        if (op == 'R') {
            recv[v] = time;
        }
        else if (op == 'S') {
            total[v] += time - recv[v];
            recv[v] = -1;
        }
    }
    for (int i = 1; i < MAX_X + 1; i++) {
        if (recv[i] != -1) {
            // Not replied yet
            total[i] = -1;
        }
        if (total[i] != 0) {
            printf("%d %d\n", i, total[i]);
        }
    }
}
