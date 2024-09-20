#include <bits/stdc++.h>

#define VALID_INDEX(i, j) ((i) >= 0 && (j) >= 0 && (i) < n && (j) < (m))

using namespace std;

struct tile {
    char type;
    bool visited;
};

struct tile matrix[1000][1000];


bool visit_room(int i, int j, int64_t current_room, int64_t n, int64_t m) {
    
    if (!VALID_INDEX(i, j) || matrix[i][j].visited || matrix[i][j].type == '#') {
        return false;
    }
    matrix[i][j].visited = true;
    visit_room(i - 1, j    , current_room, n, m);
    visit_room(i    , j - 1, current_room, n, m);
    visit_room(i + 1, j    , current_room, n, m);
    visit_room(i    , j + 1, current_room, n, m);
    return true;
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    int64_t current_room = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j].type;
            matrix[i][j].visited = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            struct tile tile = matrix[i][j];
            if (!tile.visited) {
                if (visit_room(i, j, current_room, n, m)) {
                    current_room++;
                }
            }
        }
    }
    cout << current_room << endl;
}