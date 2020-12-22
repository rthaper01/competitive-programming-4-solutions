#include <iostream>
#include <stack>
#include <vector>
#include "stdio.h"

using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);

    stack<int> pile;
    stack<int> aux;

    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &a);
        aux.push(a);
    }
    int moves = 0;
    while (true) {
        if (!pile.empty() && (pile.top() == aux.top())) {
            pile.pop();
            aux.pop();
        }
        else {
            pile.push(aux.top());
            aux.pop();
        }
        moves++;
        if (aux.empty() && pile.empty()) {
            printf("%d\n", moves);
            break;
        }
        else if (aux.empty() && !pile.empty()) {
            printf("impossible\n");
            break;
        }        
    }
    return 0;
}