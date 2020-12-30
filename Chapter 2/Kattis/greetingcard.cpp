#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include "stdio.h"

typedef long long ll;

using namespace std;

struct Pair_hash {
    size_t operator()(const pair<ll, ll> p) const {
        return size_t(p.first) << 32 | p.second;
    }
};

ll count_valid(unordered_set<pair<ll, ll>, Pair_hash>& points, pair<ll, ll> point) {
    ll total = 0;
    vector<pair<ll, ll>> neighbors;
    neighbors.push_back({point.first + 0, point.second + 2018});
    neighbors.push_back({point.first + 0, point.second - 2018});
    neighbors.push_back({point.first + 2018, point.second + 0});
    neighbors.push_back({point.first - 2018, point.second + 0});
    neighbors.push_back({point.first + 1680, point.second + 1118});
    neighbors.push_back({point.first - 1680, point.second + 1118});
    neighbors.push_back({point.first + 1680, point.second - 1118});
    neighbors.push_back({point.first - 1680, point.second - 1118});
    neighbors.push_back({point.first + 1118, point.second + 1680});
    neighbors.push_back({point.first - 1118, point.second + 1680});
    neighbors.push_back({point.first + 1118, point.second - 1680});
    neighbors.push_back({point.first - 1118, point.second - 1680});

    for (auto& p : neighbors) {
        if (points.count(p) > 0) {
            total++;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, x, y;
    cin >> n;

    unordered_set<pair<ll, ll>, Pair_hash> points;
    
    ll ans = 0;
    while (n--) {
        cin >> x >> y;
        pair<int, int> pt {x, y};
        points.insert(pt);
        ans += count_valid(points, pt);
    }
    cout << ans << endl;
    return 0;
}