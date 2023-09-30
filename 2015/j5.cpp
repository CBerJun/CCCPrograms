#include <cstdio>
#include <unordered_map>

using namespace std;

const int HASH_UNIT = 250 + 1;

struct NKM {
    int N, K, min;

    NKM(int N, int K, int min) : N(N), K(K), min(min) {}

    bool operator==(const NKM& other) const {
        return N == other.N && K == other.K && min == other.min;
    }
};

struct HashNKM {
    size_t operator()(const NKM& nkm) const {
        // Since N, K and min are small
        return nkm.N * HASH_UNIT * HASH_UNIT
               + nkm.K * HASH_UNIT
               + nkm.min;
    }
};

unordered_map<NKM, int, HashNKM> cache;

int distribute(int N, int K, int min = 1) {
    NKM nkm = NKM(N, K, min);
    if (cache.find(nkm) != cache.end()) {
        return cache[nkm];
    }
    int res;
    if (K == 1) {
        // Only person gets all pies
        res = (N >= min ? 1 : 0);
    }
    else {
        res = 0;
        // This N / K + 1 optimization (rather than writing N)
        // is actually important...
        for (int i = min; i < N / K + 1; i++) {
            res += distribute(N - i, K - 1, i);
        }
    }
    cache[nkm] = res;
    return res;
}

int main() {
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);
    printf("%d\n", distribute(N, K));
    return 0;
}
