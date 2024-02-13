/*
 * j5.3-1, j5.3-3 didn't pass. I don't know why.
 *
 * EDIT 2024.02.11
 * I spent 18 minutes reviewing my code and found the mistake.
 * I constructed a counterexample:
 *      8
 *      2 6 3  # Notice it's 2 6 3 not 2 3 6!
 *      2 3 5
 *      2 2 4
 *      1 8
 *      0
 *      1 7
 *      1 2
 *      1 5
 * The correct answer is "Y 4" while the program gives "Y 5".
 * Using 2 3 6 instead of 2 6 3, it gives the correct answer.
 * The reason is because of caching--our program ignores next pages
 * that have been `visited`, and calculates the result based on the
 * `visited` set given in this `visit`, but next time it may change,
 * making the answer in our cache wrong.
 */

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
