#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<vector<int>, vector<vector<int>>> grafo;

vector<vector<int>> comp_conexas(grafo g) {
    vector<vector<int>> comps;
    auto vert = get<0>(g);
    vector<int> visitados(vert.size(), 0);
    for (int i = 0; i < vert.size(); i++) {
        if (!visitados[vert[i]]) {
            vector<int> comp;
            dfs(g, vert[i], visitados, comp);
            comps.push_back(comp);
        }
    }
    return comps;
}

void dfs(grafo g, int v, vector<int> visitados, vector<int> comp) {
    visitados[v] = 1;
    comp.push_back(v);
    auto vert = get<0>(g);
    auto e = get<1>(g);
    for (auto u : e[v]) {
        if (!visitados[u]) {
            dfs(g, u, visitados, comp);
        }
    }
}

int main () {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> v(n);
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        v.push_back(i);
        e.push_back(vector<int>());
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e.at(a).push_back(b);
        e.at(b).push_back(a);
    }
    grafo g = {v, e};
    vector<vector<int>> comps = comp_conexas(g);
    sort(comps.begin(), comps.end());

}
