#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

/**Algorítmo de Dijkstra adaptado de
 * https://ic.unicamp.br/~ruben/2024/S1-MC558/files/Slides_MC558_Aula_11_Grafos_11.pdf
 */

typedef struct aresta {
    int v, c;
    struct aresta *next;
} aresta;

int *d;
int *d2;
int *p;

void initializeSingleSource(int n, int s) {
    for (int i = 0; i < n; i++) {
        d[i] = __INT_MAX__ - 1;
        d2[i] = __INT_MAX__ - 1;
        p[i] = -1;
    }
    d[s] = 0;
    d2[s] = 0;
}

int w(aresta **arestas, int u, int v) {
    for (aresta *a = arestas[u]; a != NULL; a = a->next) {
        if (a->v == v) {
            return a->c;
        }
    }
    return __INT_MAX__;
}

void relax(int u, int v, aresta **arestas) {
    if (d[v] == d[u] + 1 && d2[v] > d2[u] + w(arestas, u, v)) {     
        d[v] = d[u] + 1;
        p[v] = u;
        d2[v] = d2[u] + w(arestas, u, v);
    } else if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        p[v] = u;
        d2[v] = d2[u] + w(arestas, u, v);
    }
}


struct comp {
    bool operator()(int u, int v) {
        if (d[u] == d[v]) {
            printf("%d %d %d %d\n", u, v, d2[u], d2[v]);
            return d2[u] > d2[v];
        } else {
            return d[u] > d[v];
        }
    }
};

void dijkstra(int n, aresta **arestas, int s) {
    initializeSingleSource(n, s);
    priority_queue<int, vector<int>, comp> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }
    do {
        int u = q.top();
        q.pop();
        for (aresta *a = arestas[u]; a != NULL; a = a->next) {
            relax(u, a->v, arestas);
            // cout <<"u = " << u << "; v = " << a->v << endl;
            // cout << "d["<< u <<"] = " << d[u] << "; d["<< a->v << "] = " << d[a->v] << endl;
        }

    } while (!q.empty());
}

void printp(int n) {
    vector<int> vec;
    int v = n - 1;
    while (v != 0) {
        vec.push_back(v + 1);
        v = p[v];
    }
    vec.push_back(1);
    cout << vec.size() << "\n";
    cout << vec[vec.size() - 1];
    for (int i = vec.size() - 2; i >= 0; i--) {
        cout << " " << vec[i];
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    d = (int*)calloc(n, sizeof(int));
    d2 = (int*)calloc(n, sizeof(int));
    p = (int*)calloc(n, sizeof(int));
    aresta **arestas = (aresta**) calloc(n, sizeof(aresta *));
    for (int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--;
        u--;
        aresta *a1, *a2;
        a1 = (aresta*) malloc(sizeof(aresta));
        a2 = (aresta*) malloc(sizeof(aresta));
        a1->v = v;
        a1->c = c;
        a1->next = arestas[u];
        a2->v = u;
        a2->c = c;
        a2->next = arestas[v];
        arestas[u] = a1;
        arestas[v] = a2;
    }
    dijkstra(n, arestas, 0);

    printp(n);
}
