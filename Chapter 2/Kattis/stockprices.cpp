#include <iostream>
#include "stdio.h"
#include <queue>
#include <map>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<int> buy_orders;
        priority_queue<int> sell_orders;
        int last_price = -1;
        while (n--) {
            string type_of_order, common1, common2;
            int shares, price;
            cin >> type_of_order >> shares >> common1 >> common2 >> price;
            if (type_of_order == "buy") {
                for (int i = 0; i < shares; i++) {
                    buy_orders.push(price);
                }
            }
            else {
                for (int i = 0; i < shares; i++) {
                    sell_orders.push(price * -1);
                }
            }
            while (!buy_orders.empty() && !sell_orders.empty() && buy_orders.top() >= sell_orders.top() * -1) {
                last_price = sell_orders.top() * -1;
                buy_orders.pop();
                sell_orders.pop();
            }
            string sell = sell_orders.empty() ? "-" : to_string(sell_orders.top() * -1);
            string buy = buy_orders.empty() ? "-" : to_string(buy_orders.top());
            string last = (last_price == -1) ? "-" : to_string(last_price);
            cout << sell << " " << buy << " " << last << endl;
        }
    }
    return 0;
}