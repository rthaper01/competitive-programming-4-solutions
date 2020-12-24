#include <iostream>
#include <stack>
#include "stdio.h"

using namespace std;

void print_stack(stack<char> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int L;
    cin >> L;

    stack<char> brackets;
    char ch;
    int i = 0;

    cin.get(ch);

    while (i < L) {
        cin.get(ch);
        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        }
        else if (ch == ')') {
            if (!brackets.empty() && brackets.top() == '(') {
                brackets.pop();
            }
            else {
                cout << ch << " " << i << endl;
                break;
            }
        }
        else if (ch == ']') {
            if (!brackets.empty() && brackets.top() == '[') {
                brackets.pop();
            }
            else {
                cout << ch << " " << i << endl;
                break;
            }
        }
        else if (ch == '}') {
            if (!brackets.empty() && brackets.top() == '{') {
                brackets.pop();
            }
            else {
                cout << ch << " " << i << endl;
                break;
            }
        }
        ++i;
    }
    if (i == L) {
        cout << "ok so far" << endl;
    }
    return 0;
}