#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef struct node {
    char value;
    vector<int> idxs;
    struct node *next;
} list_node;

int main() {
    int n;
    cin >> n;
    string str = "";
    char caracteres[26];
    unordered_map<char, list_node*> chars;
    for (char c = 'a'; c <= 'z'; c++) {
        caracteres[c - 'a'] = c;
        chars.insert({c, NULL});
    }
    char buf[2];
    buf[1] = '\0';
    int size = 0;
    for (int _ = 0; _ < n; _++) {
        int o;
        char c1, c2;
        cin >> o;
        switch (o) {
        case 1:
            cin >> c1;
            str.push_back(c1);
            chars.insert_or_assign
            chars[c1].insert(size);
            size++;
            break;
        case 2:
            if (size != 0) {
                c1 = str[size - 1];
                str.pop_back();
                chars.at(c1).erase(size - 1);
                size--;
            }
            break;
        case 3:
            cin >> c1;
            cin >> c2;
            if (c1 != c2) {
                for (int i = 0; i < 26; i++) {
                    if (caracteres[i] == c1) {
                        caracteres[i] = c2;
                    }
                }
            }
            break;
        }
    }
    if (size == 0) {
        cout << "The final string is empty" << endl;
    } else {
        for (int i = 0; i < size; i++) {
            char c = str[i];
            str[i] = caracteres[c - 'a'];
        }
        cout << str << endl;
    }
}
