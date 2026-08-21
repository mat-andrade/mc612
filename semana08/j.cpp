#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct CompareFirst {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.first > p2.first;
    }
};

int main() {
    bool soup, spicy;
    int tsoup, tspicy, index, n;
    index = 0;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareFirst> soupPot, spicyPot;
    while (n--) {
        cin >> tspicy >> tsoup >> spicy >> soup;
        if (spicy && soup) {
            if (tspicy < tsoup) {
                spicyPot.push(make_pair(tspicy, ++index));
            } else {
                soupPot.push(make_pair(tsoup, ++index));
            }
        }
        else if (spicy) {
            spicyPot.push(make_pair(tspicy, ++index));
        }
        else {
            soupPot.push(make_pair(tsoup, ++index));
        }
    }
    cout << spicyPot.size();
    while (!spicyPot.empty()) {
        cout << " " << spicyPot.top().second;
        spicyPot.pop();
    }
    cout << endl;
    cout << soupPot.size();
    while (!soupPot.empty()) {
        cout << " " << soupPot.top().second;
        soupPot.pop();
    }
    cout << endl;
}