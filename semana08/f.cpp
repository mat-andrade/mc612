#include <iostream>
#include <string.h>

using namespace std;

void computeLPSArray(char *pat, int M, int *lps) {
    // Slide 9
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPsearch(char *pat, char *txt) {
    // Slide 9
    int count = 0;
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            count++;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return count;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    cout << KMPsearch((char *)pat.c_str(), (char *)txt.c_str()) << endl;
    return 0;
}