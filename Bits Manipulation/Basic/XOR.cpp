#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int c = 1;
    int d = 2;
    int e = 4;
    int f = 5;

    vector<pair<string, int>> vars = {
        {"a", a}, {"b", b}, {"c", c}, {"d", d}, {"e", e}, {"f", f}
    };

    for (int i = 0; i < vars.size(); i++) {
        for (int j = 0; j < vars.size(); j++) {
            cout << vars[i].first << " ^ " << vars[j].first
                 << " = " << (vars[i].second ^ vars[j].second) << endl;
        }
    }

    return 0;
}
