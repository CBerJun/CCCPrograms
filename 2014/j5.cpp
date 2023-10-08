#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> l;
    vector<pair<string, string>> stub;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        l.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool found = false;
        if (l[i] == s) {
            goto bad;
        }
        for (int j = 0; j < stub.size(); j++) {
            if (stub[j].first == s) {
                if (stub[j].second == l[i]) {
                    auto it = stub.begin();
                    advance(it, j);
                    stub.erase(it);
                    found = true;
                    break;
                }
                else {
                    goto bad;
                }
            }
        }
        if (!found) {
            stub.push_back(make_pair(l[i], s));
        }
    }
    printf("good\n");
    goto exit;
bad:
    printf("bad\n");
exit:
    return 0;
}
