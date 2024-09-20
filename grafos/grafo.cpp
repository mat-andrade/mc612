#include <bits/stdc++.h>

using namespace std;

typedef struct aresta {
    int64_t v;
    int64_t c;
    struct aresta *next;
} Aresta;

Aresta **ug_from_stdin(int64_t n, int64_t m) {
    m *= 2;
    Aresta *arestas = (Aresta *) malloc(m * sizeof(aresta));
    Aresta **grafo = (Aresta **) calloc(n, sizeof(Aresta *));
    for (size_t i = 0; i < m; i += 2) {
        int64_t u, v;
        cin >> u >> v;
        u--;
        v--;
        arestas[i] = {.v = v, .next = grafo[u]};
        arestas[i + 1] = {.v = u, .next = grafo[v]};
        grafo[u] = &arestas[i];
        grafo[v] = &arestas[i + 1];
    }
    return grafo;
}

Aresta **dg_from_stdin(int64_t n, int64_t m) {
    Aresta *arestas = (Aresta *) malloc(m * sizeof(aresta));
    Aresta **grafo = (Aresta **) calloc(n, sizeof(Aresta *));
    for (size_t i = 0; i < m; i++) {
        int64_t u, v;
        cin >> u >> v;
        u--;
        v--;
        arestas[i] = {.v = v, .next = grafo[u]};
        grafo[u] = &arestas[i];
    }
    return grafo;
}

Aresta **wug_from_stdin(int64_t n, int64_t m) {
    m *= 2;
    Aresta *arestas = (Aresta *) malloc(m * sizeof(aresta));
    Aresta **grafo = (Aresta **) calloc(n, sizeof(Aresta *));
    for (size_t i = 0; i < m; i += 2) {
        int64_t u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        arestas[i] = {.v = v, .c = c, .next = grafo[u]};
        arestas[i + 1] = {.v = u, .c = c, .next = grafo[v]};
        grafo[u] = &arestas[i];
        grafo[v] = &arestas[i + 1];
    }
    return grafo;
}

Aresta **wdg_from_stdin(int64_t n, int64_t m) {
    Aresta *arestas = (Aresta *) malloc(m * sizeof(aresta));
    Aresta **grafo = (Aresta **) calloc(n, sizeof(Aresta *));
    for (size_t i = 0; i < m; i++) {
        int64_t u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        arestas[i] = {.v = v, .c = c, .next = grafo[u]};
        grafo[u] = &arestas[i];
    }
    return grafo;
}

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
