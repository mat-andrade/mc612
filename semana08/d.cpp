#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    uint32_t count;
    TrieNode *zero, *one;
};


#define ALLOC_NODE(_dst, _zero, _one) do {\
    (_dst) = (TrieNode *) malloc(sizeof(TrieNode));\
    (_dst)->count = 0;\
    (_dst)->zero = _zero;\
    (_dst)->one = _one;\
} while(0)

void trie_add(TrieNode *node, uint32_t x, int b) {
    if(b == -1){
        node->count++;
        return;
    }
    uint32_t bit = x & (1 << b);
    if (bit) {
        if (node->one == NULL) 
            ALLOC_NODE(node->one, NULL, NULL);
        trie_add(node->one, x, b - 1);
    } else {
        if (node->zero == NULL) 
            ALLOC_NODE(node->zero, NULL, NULL);
        trie_add(node->zero, x, b - 1);
    }
    node->count++;
}


void trie_rem(TrieNode *node, uint32_t x, int b) {
    if(b == -1){
        node->count--;
        return;
    }
    uint32_t bit = x & (1 << b);
    if (bit) {
        trie_rem(node->one, x, b - 1);
    } else {
        trie_rem(node->zero, x, b - 1);
    }
    node->count--;
}


int trie_query(TrieNode *node, uint32_t x, int b) {
    if(b == -1){
        return 0;
    }
    uint32_t bit = x & (1 << b);
    if (bit) {
        if (node->zero && node->zero->count > 0) {
            return trie_query(node->zero, x, b - 1) ^ (1 << b);
        } else if (node->one && node->one->count > 0) {
            return trie_query(node->one, x, b - 1);
        } else {
            return x ^ 0;
        }
    } else {
        if (node->one && node->one->count > 0) {
            return trie_query(node->one, x, b - 1)  ^ (1 << b);
        } else if (node->zero && node->zero->count > 0) {
            return trie_query(node->zero, x, b - 1);
        } else {
            return x ^ 0;
        }
    }
}

int main() {
    uint32_t q;
    TrieNode *trie = new TrieNode();
    trie->count = 0;
    trie->one = trie->zero = NULL;
    trie_add(trie, 0, 31);
    for (cin >> q; q > 0; q--) {
        char o;
        uint32_t x;
        cin >> o >> x;
        switch (o) {
            case '+':
                trie_add(trie, x, 31);
                break;
            case '-':
                trie_rem(trie, x, 31);
                break;
            case '?':
                cout << trie_query(trie, x, 31) << "\n";
                break;
        }
    }
}
