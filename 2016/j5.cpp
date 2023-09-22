#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int q, n;
    scanf("%d", &q);
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    if (q == 1) {
        sort(b, b + n);
    }
    else {
        sort(b, b + n, greater<int>());
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max(a[i], b[i]);
    }
    printf("%d\n", sum);
    return 0;
}
