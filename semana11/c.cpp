#include <bits/stdc++.h>

using namespace std;

string strs[100001];
bool r[100001];
int main() {
    int t;
    
    for (cin >> t; t > 0; t--) {
        int n;
        cin >> n;
        unordered_set<string> string_set;
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
            r[i] = 0;
            string_set.emplace(strs[i]);
        }
        
        for (int i = 0; i < n; i++) {
            string str = strs[i];
            for (int j = 1; j < str.size(); j++) {
                string p = str.substr(0, j);
                string s = str.substr(j);
                if (string_set.count(p) && string_set.count(s)) {
                    r[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << r[i];
        }
        cout << endl;
    }
}
