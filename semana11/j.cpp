#include <bits/stdc++.h>
using namespace std;

struct Comp {
    int head;
    set<int, greater<int>> vertices;
};

int comp[200011];
unordered_map<int, Comp> comps;

void join(int u, int v) {
    if (comp[u] == comp[v]) {
        return;
    }
    int c1 = comp[u], c2 = comp[v];
    if (comps[c1].vertices.size() >= comps[c2].vertices.size()) {
        for (auto a : comps[c2].vertices) {
            comp[a] = c1;
        }
        comps[c1].vertices.merge(comps[c2].vertices);
        comps.erase(c2);
    } else {
        for (auto a : comps[c1].vertices) {
            comp[a] = c2;
        }
        comps[c2].vertices.merge(comps[c1].vertices);
        comps.erase(c1);
    }
}

int find(int u, int k) {
    auto& s = comps[comp[u]].vertices;
    if (k > s.size()) {
        return -1;
    }
    return *next(s.begin(), k - 1);
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        comp[i] = i;
        comps[i] = { i };
        comps[i].vertices.emplace(i);
    }
    for (; q > 0; q--) {
        int t, u, v, k;
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            join(u, v);
        } else {
            cin >> u >> k;
            cout << find(u, k) << '\n';
        }
    }

}
