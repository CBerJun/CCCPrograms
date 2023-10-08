#include <cstdio>
#include <vector>

using namespace std;

vector<int> numbers;

int main() {
    int k, m;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        numbers.push_back(i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int mul;
        scanf("%d", &mul);
        for (int i = numbers.size() / mul; i >= 1; i--) {
            auto it = numbers.begin();
            advance(it, i * mul - 1);
            numbers.erase(it);
        }
    }
    for (int i : numbers) {
        printf("%d\n", i);
    }
    return 0;
}
