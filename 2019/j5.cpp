/*
 * This problem has more than 1 possible outputs for most of the test
 * cases, so it does not work well with testrunner.
 * This might get TLE for some cases like j5.05.
 */

#include <iostream>
#include <string>

using namespace std;

const int RULE_NUM = 3;

string target;
struct Rule {
    string origin;
    string target;
} rules[RULE_NUM];
string answer = "";

bool calc(string origin, int steps) {
    // cout << "calc: " << origin << " " << steps << endl;
    if (steps == 0) {
        return origin == target;
    }
    size_t origin_len = origin.length();
    for (int i = 0; i < RULE_NUM; i++) {
        size_t rule_origin_len = rules[i].origin.length();
        if (origin_len < rule_origin_len) {
            continue;
        }
        for (int j = 0; j <= origin_len - rule_origin_len; j++) {
            if (origin.substr(j, rule_origin_len) == rules[i].origin) {
                string new_s = origin;
                new_s.replace(j, rule_origin_len, rules[i].target);
                // cout << "replace: " << origin << " " << new_s << endl;
                if (calc(new_s, steps - 1)) {
                    answer.insert(0, to_string(i + 1)
                        + " "
                        + to_string(j + 1)
                        + " "
                        + new_s
                        + "\n");
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < RULE_NUM; i++) {
        cin >> rules[i].origin >> rules[i].target;
    }
    int steps;
    string origin;
    cin >> steps >> origin >> target;
    calc(origin, steps);  // == true
    cout << answer;
    return 0;
}
