#include <iostream>
#include <vector>
#include <sstream>
#include "stdio.h"

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

vll ft;

ll rsq(int j) {
    ll sum = 0;
    for (; j; j -= LSOne(j)) {
        sum += ft[j];
    }
    return sum;
}

ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

void update(int i, ll v) {
    for (; i < (int) ft.size(); i += LSOne(i)) {
        ft[i] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, Q;
    scanf("%lld%lld\n", &N, &Q);

    ft.assign(N + 1, 0);

    for (ll j = 0; j < Q; j++) {
        char ch;
        ll i, d;
        scanf("%c", &ch);
        if (ch == '+') {
            scanf("%lld%lld\n", &i, &d);
            update(i + 1, d);
        }
        else {
            scanf("%lld\n", &i);
            printf("%lld\n", rsq(i));
        }
    }
    return 0;
}
