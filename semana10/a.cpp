#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 100

int32_t table[MAX_LEN][MAX_LEN];

int32_t score[4] = {2, -1, -1, -1};

void string_alignment(string p, string q) {
	int32_t n = p.size(), m = q.size();
	for (int i = 0; i <= n; i++) {
		table[i][0] = i * score[2];
	}
	for (int i = 0; i <= m; i++) {
		table[0][i] = i * score[3];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (p[i - 1] == q[i - 1]) {
				table[i][j] = table[i - 1][j - 1] + score[0];
			} else {
				table[i][j] = table[i - 1][j - 1] + score[1];
			}
			table[i][j] = max(table[i][j], table[i - 1][j] + score[2]);
			table[i][j] = max(table[i][j], table[i - 1][j] + score[3]);
		}
	}
}

int main() {
	string p, q;
	while (cin >> p >> q) {
		
	}
}
