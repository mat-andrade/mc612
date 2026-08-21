#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    for (cin >> n; n > 0; n--) {
        string s;
        cin >> s;
        int len = s.size();
        s.append(s);
        vector<int> candidatos;
        char min_chr = 'z' + 1;
        for (int i = 0; i < len; i++) {
            if (s[i] < min_chr) {
                candidatos.clear();
                candidatos.push_back(i);
                min_chr = s[i];
            }
        }
        bool mudou = true;
        for (int k = 1; candidatos.size() > 1 && mudou; k++) {
            mudou = true;
            min_chr = 127;
            vector<int> novos_candidatos;
            for (int i : candidatos) {
                if (s[i + k] < min_chr) {
                    novos_candidatos.clear();
                    novos_candidatos.push_back(i);
                    min_chr = s[i + k];
                }
            }
            if (novos_candidatos.size() == 0) {
                mudou = false;
            }
            candidatos = move(novos_candidatos);
        }
    }

}
