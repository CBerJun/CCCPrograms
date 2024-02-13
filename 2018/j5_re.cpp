#include <iostream>
#include <vector>
#include <deque>
#include <bitset>
#include <utility>

using namespace std;

vector<int> adj[10001];
bitset<10001> visited;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    deque<pair<int, int>> q;
    // page #, steps
    q.push_back({1, 1});
    int res = -1;
    while (!q.empty()) {
        int cur = q.front().first, steps = q.front().second;
        q.pop_front();
        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        if (adj[cur].empty() && res == -1) {
            res = steps;
        }
        for (int next : adj[cur]) {
            q.push_back({next, steps + 1});
        }
    }
    cout << (visited.count() == N ? 'Y' : 'N') << '\n';
    cout << res << '\n';
}
