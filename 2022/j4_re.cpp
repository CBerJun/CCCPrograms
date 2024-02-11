#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

unordered_map<ll, vector<ll>> same;
unordered_map<ll, vector<ll>> nsame;
const ll POW27S[10] = {
    1ll,
    27ll,
    729ll,
    19683ll,
    531441ll,
    14348907ll,
    387420489ll,
    10460353203ll,
    282429536481ll,
    7625597484987ll,
};

ll myhash(const char *n) {
    ll h = 0;
    for (int i = 0; n[i]; ++i) {
        h += (n[i] - 'A' + 1) * POW27S[i];
    }
    return h;
}

bool is_in(ll h1, vector<ll> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (h1 == v[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, y;
    char t1[11], t2[11], t3[11];
    scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        scanf("%s %s", t1, t2);
        same[myhash(t1)].push_back(myhash(t2));
    }
    scanf("%d", &y);
    for (int i = 0; i < y; ++i) {
        scanf("%s %s", t1, t2);
        nsame[myhash(t1)].push_back(myhash(t2));
    }
    int g;
    scanf("%d", &g);
    int res = x;
    for (int i = 0; i < g; ++i) {
        scanf("%s %s %s", t1, t2, t3);
        ll h1 = myhash(t1), h2 = myhash(t2), h3 = myhash(t3);
        if (is_in(h2, same[h1]) || is_in(h1, same[h2])) {
            --res;
        }
        if (is_in(h3, same[h1]) || is_in(h1, same[h3])) {
            --res;
        }
        if (is_in(h3, same[h2]) || is_in(h2, same[h3])) {
            --res;
        }
        if (is_in(h2, nsame[h1]) || is_in(h1, nsame[h2])) {
            ++res;
        }
        if (is_in(h3, nsame[h1]) || is_in(h1, nsame[h3])) {
            ++res;
        }
        if (is_in(h3, nsame[h2]) || is_in(h2, nsame[h3])) {
            ++res;
        }
    }
    printf("%d\n", res);
}
