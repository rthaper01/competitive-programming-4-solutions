#include <iostream>
#include <stack>
#include "stdio.h"

using namespace std;

int main() {
    int N, card;
    stack<int> cards;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &card);
        if (cards.empty() || (cards.top() + card ) % 2 == 1) {
            cards.push(card);
        }
        else {
            cards.pop();
        }
    }
    printf("%d\n", (int) cards.size());
    return 0;
}