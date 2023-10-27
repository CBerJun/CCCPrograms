/* I spent 2 hours and eventually learnt about the rule of
   three... C++ is hard... */

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Config {
public:
    int n;
    vector<int> *data;  // coins from 0 to n-1

    Config(int n) : n(n), data(new vector<int>[n]) {}

    Config(const Config &other) : Config(other.n) {
        for (int i = 0; i < n; i++) {
            data[i] = other.data[i];
        }
    }

    Config& operator=(const Config &other) {
        if (this != &other) {
            delete[] data;
            n = other.n;
            data = new vector<int>[n];
            for (int i = 0; i < n; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Config() {
        delete[] data;
    }

    int id() const {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int coin : data[i]) {
                res += pow(n, coin) * i;
            }
        }
        return res;
    }
};

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        Config init(n);
        size_t n_ids = pow(n, n);
        bool *queued = new bool[n_ids]();
        for (int i = 0; i < n; i++) {
            int coin;
            scanf("%d", &coin);
            init.data[i].push_back(coin - 1);
        }
        queue<pair<Config, int>> configs;
        configs.push(make_pair(init, 0));
        queued[init.id()] = true;
        while (!configs.empty()) {
            const pair<Config, int> cur_pair = configs.front();
            configs.pop();
            const Config &cur = cur_pair.first;
            int cur_id = cur.id();

            bool found = true;
            for (int i = 0; i < n; i++) {
                if (cur.data[i].empty() || cur.data[i].back() != i) {
                    found = false;
                    break;
                }
            }
            if (found) {
                printf("%d\n", cur_pair.second);
                goto exit;
            }

            // printf("id: %d\n", cur_id);
            queued[cur_id] = true;
            for (int try_id = 0; try_id < n * 2 - 2; try_id++) {
                int i = (try_id + 1) / 2;
                int tg = (try_id % 2 == 0) ? i + 1 : i - 1;
                // printf("i, tg: %d, %d\n", i, tg);
                if (cur.data[i].empty()) {
                    continue;
                }
                int moving = cur.data[i].back();  // the coin moving
                if (cur.data[tg].empty() || moving < cur.data[tg].back()) {
                    Config next = cur;
                    next.data[i].pop_back();
                    next.data[tg].push_back(moving);
                    int next_id = next.id();
                    if (queued[next_id]) {
                        continue;
                    }
                    // printf("moving %d from %d to %d; id: %d\n",
                    //        moving, i, tg, next_id);
                    configs.push(make_pair(next, cur_pair.second + 1));
                    queued[next_id] = true;
                }
            }
        }
        printf("IMPOSSIBLE\n");
exit:
        delete[] queued;
    }
    return 0;
}

int test() {
    Config c(3);
    c.data[0].push_back(2);
    c.data[1].push_back(1);
    c.data[1].push_back(0);
    printf("%d\n", c.id());
    Config c2 = c;
    c2.data[0].pop_back();
    c2.data[1].push_back(2);
    printf("%d\n", c2.id());
    queue<Config> cgs;
    cgs.push(c);
    Config ref = cgs.front();
    cgs.pop();
    printf("%d\n", ref.id());
    printf("ok");
    return 0;
}
