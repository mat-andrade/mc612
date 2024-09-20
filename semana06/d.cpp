#include <bits/stdc++.h>

using namespace std;


typedef struct aresta {
    int64_t v;
    struct aresta *next;
} Aresta;

vector<tuple<int64_t, int64_t>> bfs(Aresta **arestas, int64_t v, int64_t n) {
    vector<tuple<int64_t, int64_t>> ret;
    bool *visited = (bool *) calloc(n, sizeof(bool));
    visited[v] = true;
    queue<int64_t> q;
    q.push(v);
    while (!q.empty()) {
        int64_t u = q.front();
        q.pop();
        for (Aresta *a = arestas[u]; a != NULL; a = a->next) {
            if (!visited[a->v]) {
                visited[a->v] = true;
                ret.push_back(make_tuple(u, a->v));
                q.push(a->v);
            }
        }
    }
    return ret;
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    Aresta **arestas = (Aresta **) calloc(m, sizeof(Aresta *));
    int64_t *degree = (int64_t *) calloc(n, sizeof(int64_t));
    int64_t max_degree = 0;
    int64_t s = 0;
    for (; m > 0; m--) {
        int64_t u, v;
        cin >> u >> v;
        u--;
        v--;
        aresta *a1, *a2;
        a1 = (aresta*) malloc(sizeof(aresta));
        a2 = (aresta*) malloc(sizeof(aresta));
        a1->v = v;
        a1->next = arestas[u];
        a2->v = u;
        a2->next = arestas[v];
        arestas[u] = a1;
        arestas[v] = a2;
        degree[u]++;
        degree[v]++;
        if (degree[u] > max_degree) {
            max_degree = degree[u];
            s = u;
        }
        if (degree[v] > max_degree) {
            max_degree = degree[v];
            s = v;
        }
        
    }
    auto a = bfs(arestas, s, n);
    for (auto x : a) {
        cout << get<0>(x) + 1 << " " << get<1>(x) + 1 << endl;
    }
}
