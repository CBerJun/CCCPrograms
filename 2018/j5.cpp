/* j5.3-1, j5.3-3 didn't pass. I don't know why. */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> nexts[10001];
unordered_map<int, int> visit_cache;

int visit(int page, unordered_set<int> visited) {
    // cout << "visit: " << page << endl;
    if (visited.find(page) != visited.end()) {
        return -1;
    }
    if (visit_cache.find(page) != visit_cache.end()) {
        return visit_cache[page];
    }
    int res;
    if (nexts[page].empty()) {
        res = 1;
    }
    else {
        unordered_set<int> visited_copy = visited;
        visited_copy.insert(page);
        int ans = -2;
        for (int next : nexts[page]) {
            int len = visit(next, visited_copy);
            if (len > 0 && (len < ans || ans == -2)) {
                ans = len;
            }
        }
        res = ans + 1;
    }
    visit_cache[page] = res;
    return res;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            nexts[i].push_back(x);
        }
    }
    unordered_set<int> visited;
    int ans = visit(1, visited);
    // cout << "visited: ";
    // for (int v : visited) {
    //     cout << v << " ";
    // }
    // cout << "\n";
    cout << (visit_cache.size() == N ? "Y" : "N") << endl;
    cout << ans << endl;
    return 0;
}
