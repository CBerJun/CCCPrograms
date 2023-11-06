#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 6;
vector<int> network[MAX];

int traverse(int i) {
    int res = 1;
    for (int j : network[i]) {
        res *= traverse(j);
    }
    res += 1;
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int inviter;
        scanf("%d", &inviter);
        network[inviter - 1].push_back(i);
    }
    printf("%d\n", traverse(n - 1) - 1);
    // -1 bacause Mark himself can't be removed
    return 0;
}
