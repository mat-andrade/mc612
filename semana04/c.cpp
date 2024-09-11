#include <iostream>
using namespace std;

int main() {
    int n, m, qcount, fcount;
    cin >> n >> m;
    qcount = 0;
    fcount = 0;

    char matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '#') {
                if (i+2 < n && j+2 < m && matrix[i+1][j] == '#' && matrix[i][j+1] == '#' && matrix[i+2][j] == '#'
                && matrix[i][j+2] == '#' && matrix[i+2][j+1] == '#') {
                    int esq = 0;
                    int dir = 0;
                    if (i+3 < n && matrix[i+3][j] == '#' && i+4 < n && matrix[i+4][j] == '#') {
                        esq = 1;
                    }
                    if ( matrix[i+1][j+2] == '#' && matrix[i+2][j+2] == '#' && i+3 < n && matrix[i+3][j+2] == '#' && i+4 < n && matrix[i+4][j+2] == '#') {
                        dir = 1;
                    } 

                    if (esq == 1 && dir == 1) {
                        if (j+3 < m && matrix[i+1][j+3] == '#' && matrix[i+3][j+3] == '#') {
                            fcount++;
                        } else {
                            qcount++;
                        }
                    } else if (esq == 1) {
                        fcount++;
                    } else if (dir == 1) {
                        qcount++;
                    }
                }
            }
        }
    }
    cout << qcount << " " << fcount << endl;
    
    return 0;
}